/**
 * KOZRUM PACKAGE INSTALLER
 *
 * @version		1.0.0
 * @copyright	2017, Kozrum
 * @license		MIT
 */

#ifndef KOZ_INSTALLER_H
#define KOZ_INSTALLER_h

#include <vector>
#include <string>

class Installer
{
public:
    Installer(std::vector<std::string> t_command, int t_command_size);
    void run();

private:
    std::vector<std::string> m_command;
    int m_command_size;
    int m_installation_type;
};

#endif
