/**
 * KOZRUM - HTML content generator
 *
 * @version     1.0.0
 * @author      Robert Monden
 * @copyright   2017, Robert Monden
 * @license     Apache 2.0
 */
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

#include "Header.h"

Header::Header()
    : m_randomGenerator((unsigned long) time(nullptr)),
      m_level(0)
{}

void Header::generate()
{
    std::vector<std::string> headers = {
            "bubbles", "watermelons", "big mountains", "have fun",
            "good luck", "champagne", "great", "eat a melon", "oh, no",
            "don't you touch my guitar.", "weird things", "what a strange lady.",
            "New York", "this is a robbery", "sir", "madam", "fantastic",
            "house party"
    };
    std::vector<std::string> usedWords {};

    std::uniform_int_distribution<int> distance(0, (int) headers.size() - 1);
    std::uniform_int_distribution<int> wordcount(1, 3);

    std::string words;
    int wordsToDisplay = wordcount(m_randomGenerator);
    bool capitalizeNextWord = true;

    std::cout << "<h" << m_level + 1 << ">";

    int i = 0;
    while (i < wordsToDisplay)
    {
        std::string randomWord = headers[distance(m_randomGenerator)];

        if (std::find(usedWords.begin(), usedWords.end(), randomWord) == usedWords.end())
        {
            if (capitalizeNextWord)
            {
                randomWord[0] = (char) toupper(randomWord[0]);
                capitalizeNextWord = false;
            }

            std::cout << randomWord;

            if (i != wordsToDisplay - 1)
            {
                if (randomWord.substr(randomWord.size() - 1, 1) == ".")
                {
                    capitalizeNextWord = true;
                    std::cout << " ";
                }
                else
                    std::cout << ", ";
            }

            i++;
            usedWords.push_back(randomWord);
        }
    }

    std::cout << "</h" << m_level + 1 << ">" << std::endl;
}

void Header::setLevel(int t_level)
{
    m_level = t_level;
}