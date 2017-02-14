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
    : m_randomGenerator((unsigned long) time(nullptr))
{}

std::string Header::generate()
{
    std::vector<std::string> headers = {
            "bubbles", "watermelons", "big mountains", "have fun",
            "good luck", "champagne", "great", "eat a melon", "oh, no",
            "don't you touch my guitar.", "weird things", "what a strange lady.",
            "New York", "this is a robbery"
    };
    std::vector<std::string> usedWords {};

    std::uniform_int_distribution<int> distance(0, (int) headers.size() - 1);
    std::uniform_int_distribution<int> wordcount(1, 3);

    std::string words;
    int wordsToDisplay = wordcount(m_randomGenerator);
    bool shouldCapitalize = true;

    int i = 0;
    while (i < wordsToDisplay)
    {
        std::string randomWord = headers[distance(m_randomGenerator)];

        if (std::find(usedWords.begin(), usedWords.end(), randomWord) == usedWords.end())
        {
            if (shouldCapitalize)
            {
                randomWord[0] = (char) toupper(randomWord[0]);
                shouldCapitalize = false;
            }

            words += randomWord;

            if (i != wordsToDisplay - 1)
            {
                if (randomWord.substr(randomWord.size() - 1, 1) == ".")
                {
                    shouldCapitalize = true;
                    words += " ";
                }
                else
                    words += ", ";
            }

            i++;
            usedWords.push_back(randomWord);
        }
    }

    return words;
}
