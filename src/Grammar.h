/**
 * KOZRUM - HTML content generator
 *
 * @version     1.0.0
 * @author      Robert Monden
 * @copyright   2017, Robert Monden
 * @license     Apache 2.0
 */

#ifndef KOZRUM_GRAMMAR_H
#define KOZRUM_GRAMMAR_H

#include <vector>

class Grammar
{
public:
    Grammar();

private:
    void set();
    std::vector<std::string>* m_grammar;
};

#endif //KOZRUM_GRAMMAR_H
