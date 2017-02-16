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

#include "Grammar.h"

Grammar::Grammar()
{
    //set();
}

void Grammar::set()
{
    m_grammar->push_back("{subject} {verb} {object}");
    m_grammar->push_back("{subject} {verb} {object} {time}");
    m_grammar->push_back("{subject} {verb} {object} {location}");
    m_grammar->push_back("{subject} {verb} {object} {location} {time}");
}