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

    // The repository name needs to have the following format: author/repository
    if (m_command[1] + " " + m_command[2] == "from repository")
    {
        m_installation_type = 0;

        if (!std::regex_match(m_command[3], std::regex(".+[a-zA-Z0-9]:[a-zA-Z0-9].+")))
        {
            report("Reading package name", false);
            report_error("Unknown package name format");
            return;
        }
    }
    else
    {
        report("Preparing operation", false);
        report_error("Operation not recognized");
        return;
    }

    if (!ask_for_confirmation())
    {
        report("Aborting installation...");
        return;
    }

    if (!check_repository_status(m_command[3]))
    {
        report("Checking repository status", false);
        report_error("Could not verify repository status");
        return;
    }
    else
        report("Checking repository status", true);
}

bool Installer::check_repository_status(std::string t_repository_name)
{
    // http_funcs.py
    return false;
}
