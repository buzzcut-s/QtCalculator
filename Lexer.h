#ifndef LEXER_H
#define LEXER_H

#include <QString>

enum TokenType
{
    End,
    Number,
    LeftParen  = '(',
    RightParen = ')',
    Plus       = '+',
    Minus      = '-',
    Multiply   = '*',
    Divide     = '/'
};

class Lexer
{
public:
    double getNumber() const;

    TokenType nextToken();
    TokenType currentToken() const;

    void setExpression(const QString& expression);

private:
    double    m_number;
    QString   m_expression;
    TokenType m_currentToken;
};

#endif  // LEXER_H
