/**
 * KOZRUM PACKAGE INSTALLER
 *
 * @version		1.0.0
 * @copyright	2017, Kozrum
 * @license		MIT
 */

#include <iostream>
#include "terminal.h"
#include "command.h"

const std::string t_kozrum_version = "1.0.0";
const int t_copyright_year = 2017;

int main()
{
    std::cout << "*** Welcome to Kozrum ***" << std::endl;
    std::cout << "Copyright: " << t_copyright_year << ", Kozrum" << std::endl;
    std::cout << "Version: " << t_kozrum_version << "\n\n";
    std::cout << "Please enter a command..." << std::endl;

    int running = true;
    std::string current_command = "";
    while (running)
    {
        std::cout << "> ";
        std::getline(std::cin, current_command);

        Command command(current_command);
        command.parse();
        command.execute();

        running = !command.is_exit();
    }

    return 0;
}
