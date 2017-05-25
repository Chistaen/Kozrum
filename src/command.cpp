/**
 * KOZRUM PACKAGE INSTALLER
 *
 * @version		1.0.0
 * @copyright	2017, Kozrum
 * @license		MIT
 */

#include "command.h"
#include "terminal.h"
#include "installer.h"
#include <iostream>
#include <sstream>

Command::Command(std::string t_command)
    : m_command(t_command)
{
    m_is_exit = false;
}

void Command::parse()
{
	std::istringstream command_separator(m_command);

	for (std::string m_command; command_separator >> m_command;)
	{
		m_parsed_command.push_back(m_command);
    }

    m_command_size = m_parsed_command.size();
}

void Command::execute()
{
    if (m_parsed_command[0] == "install")
    {
        report("Preparing to install package...");
        Installer installer(m_parsed_command, m_command_size);
        installer.run();
    }
    else if (m_parsed_command[0] == "exit")
    {
        m_is_exit = true;
    }
    else if (m_parsed_command[0] == "help")
    {
        display_all();
    }
    else if (m_parsed_command[0] == "clear")
    {
        clear_screen();
    }
    else
    {
        report("Executing command", false);
        report_error("Command not found");
    }
}

bool Command::is_exit()
{
    return m_is_exit;
}

void Command::display_all()
{
    if (m_parsed_command.size() > 1)
    {
        report_error("Too many arguments");
        return;
    }

    std::string commands[] = {
        "clear", "exit", "help", "install"
    };

    for (std::string command : commands)
    {
        std::cout << command << " ";
    }

    std::cout << std::endl;
}
