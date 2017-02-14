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
    std::uniform_int_distribution<int> distance(1, 10);
    std::uniform_int_distribution<int> levelDistance(0, 3);

    std::string currentSection = "init";
    std::vector<std::string> closeTags;

    int nr = distance(randomGenerator);
    int currentLevel = 0;
    int maxLevel = levelDistance(randomGenerator);

    while (nr > 0)
    {
        std::cout << "<h" << currentLevel + 1 << ">" << header.generate() << "</h"
                  << currentLevel + 1 << ">" << std::endl;

        if (currentLevel > maxLevel)
        {
            currentLevel = 0;
            maxLevel = levelDistance(randomGenerator);
            std::cout << std::endl;
        }
        else
            currentLevel++;

        nr--;
    }

    return 0;
}