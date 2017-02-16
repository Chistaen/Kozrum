/**
 * KOZRUM - HTML content generator
 *
 * @version     1.0.0
 * @author      Robert Monden
 * @copyright   2017, Robert Monden
 * @license     Apache 2.0
 */

#ifndef KOZRUM_SECTION_H
#define KOZRUM_SECTION_H

#include "Grammar.h"

class Paragraph
{
public:
    Paragraph(Grammar t_grammar);
    void display();

private:
    Grammar m_grammar;
};

#endif //KOZRUM_CONTENT_H
