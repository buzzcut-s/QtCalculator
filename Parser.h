#ifndef PARSER_H
#define PARSER_H

#include "Lexer.h"

class Parser
{
public:
    explicit Parser(Lexer* lexer);

    double parsePrimaryExpression();
    double parseMulDiv();
    double parseAddSub();

    double calculate();

private:
    Lexer* m_lexer;
};

#endif  // PARSER_H
