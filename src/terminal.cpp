/**
 * KOZRUM PACKAGE INSTALLER
 *
 * @version		1.0.0
 * @copyright	2017, Kozrum
 * @license		MIT
 */

#include "terminal.h"
#include <iostream>
#include <sys/ioctl.h>
#include <string>

void report(std::string t_message)
{
    std::cout << t_message << std::endl;
}

void report(std::string t_message, bool t_status)
{
    std::cout << t_message << "...";

    // Get the terminal size
    struct winsize terminal_size;
    ioctl(0, TIOCGWINSZ, &terminal_size);

    // Subtract the message length (including the three dots) from the terminal size
    int message_length = t_message.length() + 3;
    int status_length = t_status ? 2 : 6;
    int amount_of_spaces = terminal_size.ws_col - (message_length + status_length);

    for (int i = 0; i < amount_of_spaces; i++)
    {
        std::cout << " ";
    }

    std::cout << (t_status ? "OK" : "FAILED") << std::endl;
}

void clear_screen()
{
    struct winsize terminal_size;
    ioctl(0, TIOCGWINSZ, &terminal_size);

    for (int i = 0; i < terminal_size.ws_row; i++)
    {
        std::cout << std::endl;
    }

    // Move the cursor to the top
    printf("\033[%d;%dH", 1, 1);
}
