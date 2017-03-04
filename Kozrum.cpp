/**
 * KOZRUM PACKAGE INSTALLER
 *
 * @version		1.0.0
 * @copyright	2017, Kozrum
 * @license		MIT
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

const std::string m_version = "1.0.0";
const int m_copyright_year = 2017;

bool awaitCommand();
void processCommand(std::string t_command);
int getCommand(std::string t_command);
bool installPackage(std::vector<std::string> t_arguments);

int main()
{
	std::cout << "*** WELCOME TO KOZRUM ***" << std::endl;
	std::cout << "Copyright: " << m_copyright_year << ", Kozrum" << std::endl;
	std::cout << "Version: " << m_version << "\n\n";
	std::cout << "Please enter a command..." << std::endl;

	bool active = true;
	while (active)
	{
		// Syntax: install from repository http://github.com/Chistaen/Kozrum.git into /srv/http
		active = awaitCommand();
	}

	return 0;
}

bool awaitCommand()
{
	std::string command;
	std::cout << "> ";
	getline(std::cin, command);

	if (command == "exit")
	{
		std::cout << "Exiting." << std::endl;
		return false;
	}
	
	processCommand(command);
	return true;
}

void processCommand(std::string t_command)
{
	std::vector<std::string> parsedCommand;
	std::istringstream commandSeparator(t_command);

	for (std::string t_command; commandSeparator >> t_command;)
	{
		parsedCommand.push_back(t_command);
	}

	if (parsedCommand.size() <= 2)
	{
		std::cout << "Invalid command." << std::endl;
		return;
	}

	int command = getCommand(parsedCommand[0]);

	if (command == -1)
	{
		std::cout << "Invalid operation " << parsedCommand[0] << std::endl;
		return;
	}

	bool result;
	if (command == 0)
		result = installPackage(parsedCommand);

	std::cout << (result ? "Done." : "Operation failed.") << std::endl;
}

int getCommand(std::string t_command)
{
	if (t_command == "install")
		return 0;
	else if (t_command == "upgrade")
		return 1;
	else
		return -1;
}

bool installPackage(std::vector<std::string> t_arguments)
{
	if (t_arguments.size() < 4)
	{
		std::cout << "No package source was provided." << std::endl;
		return false;
	}
	else if (t_arguments.size() < 6)
	{
		std::cout << "No target directory was given." << std::endl;
		return false;
	}

	std::string source = t_arguments[1] + " " + t_arguments[2];
	std::string target = t_arguments[3] + " " + t_arguments[4];

	if (source != "from repository")
	{
		std::cout << "Invalid source " << t_arguments[1] << std::endl;
		return false;
	}
	else if (t_arguments[3] != "into")
	{
		std::cout << "Invalid target operator " << t_arguments[3] << std::endl;
		return false;
	}

	std::cout << "Installing package..." << std::endl;

	return true;
}