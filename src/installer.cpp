/**
 * KOZRUM PACKAGE INSTALLER
 *
 * @version		1.0.0
 * @copyright	2017, Kozrum
 * @license		MIT
 */

#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include "http.h"
#include "installer.h"
#include "terminal.h"

Installer::Installer(std::vector<std::string> t_command, int t_command_size) :
    m_command(t_command),
    m_command_size(t_command_size)
{}

void Installer::run()
{
    if (m_command_size < 4)
    {
        report("Validating command", false);
        report_error("Too few parameters.");
        return;
    }

    // The repository name needs to have the following format: author:repository
    if (m_command[1] + " " + m_command[2] == "from repository")
    {
        m_installation_type = 0;

        if (!std::regex_match(m_command[3], std::regex(".+[a-zA-Z0-9]:[a-zA-Z0-9].+")))
        {
            report("Reading package name", false);
            report_error("Unknown package name format");
            return;
        }

        m_repository_name = m_command[3];
        set_repo_url();

        // Note: move to separate method
        if (!check_repository_status())
        {
            report("Checking repository status", false);
            report_error("Could not verify repository status. Repository might not exist.");
            return;
        }
        else
            report("Checking repository status", true);

        report("Preparing to fetch git file at: " + m_repo_url);

        if (!ask_for_confirmation())
        {
            report("Aborting installation...");
            return;
        }

        if (m_command_size > 4 && m_command[4] == "here")
        {
            m_command[4] = ".";
        }

        std::string shell_command = "git clone " + m_repo_url + (m_command_size > 4 ? " " + m_command[4] : "");

        // Todo: move to terminal.cpp
        if (system(NULL))
        {
            std::cout << shell_command << std::endl;
            int exit_code = system(shell_command.c_str());

            if (exit_code != 0)
            {
                report("Cloning Git repository", false);
                report_error("Could not clone git repository.");
                return;
            }
            else
            {
                report("Cloning Git repository", true);
            }
        }
        else
        {
            report_error("No terminal found.");
            return;
        }

        report ("Repository cloned");
    }
    else
    {
        report("Preparing operation", false);
        report_error("Operation not recognized");
        return;
    }

    if (ask_for_confirmation("Detect and execute SQL files?"))
    {
        report("Preparing to locate .sql files...");
    }
    else
        return;
}

std::vector<std::string> Installer::parse_repository_name()
{
    std::vector<std::string> parsed_repo;
    std::string delimiter = ":";
    std::string author = m_repository_name.substr(0, m_repository_name.find(delimiter));

    // Ignore the 'author:' part, since we only need the name of the repository
    int begin_here_for_repo = author.size() + 1;
    std::string repository = m_repository_name.substr(begin_here_for_repo, m_repository_name.size());

    parsed_repo.push_back(author);
    parsed_repo.push_back(repository);
    return parsed_repo;
}

bool Installer::check_repository_status()
{
    HTTP connection(m_repo_url);
    bool connection_attempt = connection.connect();

    return connection_attempt;
}

void Installer::set_repo_url()
{
    std::vector<std::string> parsed_repo_name = parse_repository_name();
    m_repo_url = "http://github.com/" + parsed_repo_name[0] + "/" + parsed_repo_name[1] + ".git";
}