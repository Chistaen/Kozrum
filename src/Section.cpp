/**
 * KOZRUM - HTML content generator
 *
 * @version     1.0.0
 * @author      Robert Monden
 * @copyright   2017, Robert Monden
 * @license     Apache 2.0
 */

#include <iostream>

#include "Section.h"

void Section::generate()
{
    std::cout << "<p>This is a paragraph.";

    std::cout << "</p>" << std::endl;
}