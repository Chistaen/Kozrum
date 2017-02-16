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
#include "Paragraph.h"

std::mt19937_64* randomGenerator;
Header* header;
Paragraph* paragraph;
Grammar* grammar;

int main()
{
    randomGenerator = new std::mt19937_64(((unsigned long) time(nullptr)));
    grammar = new Grammar();

    std::uniform_int_distribution<int> sections(2, 10);
    std::uniform_int_distribution<int> levels(1, 3);
    std::uniform_int_distribution<int> paragraphs(1, 5);

    std::vector<std::string> closeTags;

    int numberOfSections = sections(*randomGenerator);
    int numberOfParagraphs = paragraphs(*randomGenerator);
    int currentLevel = 0;
    int maxLevel = levels(*randomGenerator);

    for (int i = 0; i < numberOfSections; i++)
    {
        while (currentLevel < maxLevel)
        {
            header = new Header(randomGenerator, currentLevel);
            header->display();

            for (int j = 0; j < numberOfParagraphs; j++)
            {
                paragraph = new Paragraph(*grammar);
                paragraph->display();
            }

            currentLevel++;

            delete header;
            header = nullptr;
            delete paragraph;
            paragraph = nullptr;
        }

        maxLevel = levels(*randomGenerator);
        numberOfParagraphs = paragraphs(*randomGenerator);
        currentLevel = 0;
        std::cout << std::endl;
    }

    delete randomGenerator;
    randomGenerator = nullptr;
    delete grammar;
    grammar = nullptr;

    return 0;
}