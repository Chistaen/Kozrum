/**
 * KOZRUM - HTML content generator
 *
 * @version     1.0.0
 * @author      Robert Monden
 * @copyright   2017, Robert Monden
 * @license     Apache 2.0
 */

#include <iostream>
#include <random>

#include "Header.h"

std::mt19937_64 randomGenerator((unsigned long) time(nullptr));
Header header;

int main() {
    std::uniform_int_distribution<int> distance(1, 12);
    std::string currentSection = "init";

    std::vector<std::string> closeTags;
    int nr = distance(randomGenerator);

    while (nr > 0)
    {
        if (currentSection == "init")
        {
            std::cout << "<h1>" << header.generate() << "</h1>" << std::endl;
        }

        nr--;
    }

    return 0;
}