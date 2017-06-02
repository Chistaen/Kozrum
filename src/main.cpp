/**
 * KOZRUM PACKAGE INSTALLER
 *
 * @version		1.0.0
 * @copyright	2017, Kozrum
 * @license		MIT
 */

#include <iostream>
#include <curl/curl.h>
#include "utils.h"
#include "command.h"
#include "argumentparser.h"

const std::string t_kozrum_version = "1.0.0";
const int t_copyright_year = 2017;

int main(int argc, char* argv[])
{
    curl_global_init(CURL_GLOBAL_ALL);

    kozrum::ArgumentParser::instantiate(argc, argv);

    if (argc > 1)
    {
        std::string str_command = "";

        for (int i = 1; i < argc; i++)
        {
            str_command += argv[i];
            str_command += " ";
        }

        kozrum::Command command(str_command);
        command.parse();
        command.execute();

        return 0;
    }

    std::cout << "*** Welcome to Kozrum ***" << std::endl;
    std::cout << "Copyright: " << t_copyright_year << ", Kozrum" << std::endl;
    std::cout << "Version: " << t_kozrum_version << "\n\n";
    std::cout << "Please enter a command..." << std::endl;

    int running = true;
    std::string current_command = "";
    while (running)
    {
        std::cout << "kozrum > ";
        std::getline(std::cin, current_command);

        kozrum::Command command(current_command);
        command.parse();
        command.execute();

        running = !command.is_exit();
    }

    curl_global_cleanup();

    return 0;
}
