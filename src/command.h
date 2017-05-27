/**
 * KOZRUM PACKAGE INSTALLER
 *
 * @version		1.0.0
 * @copyright	2017, Kozrum
 * @license		MIT
 */

#ifndef KOZ_COMMAND_H
#define KOZ_COMMAND_H

#include <string>
#include <vector>

class Command
{
public:
    Command(std::string t_input);
    void parse();
    void execute();
    bool is_exit();

private:
    static std::vector<std::string> m_last_command;
    std::string m_command;
    std::vector<std::string> m_parsed_command;
    int m_command_size;
    bool m_is_exit;
    void display_all();
};

#endif
