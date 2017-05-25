/**
 * KOZRUM PACKAGE INSTALLER
 *
 * @version		1.0.0
 * @copyright	2017, Kozrum
 * @license		MIT
 */

#ifndef KOZ_TERMINAL_H
#define KOZ_TERMINAL_H

#include <string>

void report(std::string t_message);
void report(std::string t_message, bool t_status);
void clear_screen();

#endif
