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
#include "Section.h"

std::mt19937_64 randomGenerator((unsigned long) time(nullptr));

Header header;
Section section;

int main() {
    std::uniform_int_distribution<int> sections(2, 10);
    std::uniform_int_distribution<int> levels(1, 3);

    std::string currentSection = "init";
    std::vector<std::string> closeTags;

    int nr = sections(randomGenerator);
    int currentLevel = 0;
    int maxLevel = levels(randomGenerator);

    for (int i = 0; i < nr; i++)
    {
        while (currentLevel < maxLevel)
        {
            header.setLevel(currentLevel);
            header.generate();
            section.generate();
            currentLevel++;
        }

        maxLevel = levels(randomGenerator);
        currentLevel = 0;
        std::cout << std::endl;
    }

    return 0;
}