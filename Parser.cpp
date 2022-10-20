#include "Parser.h"

#include <QDebug>

Parser::Parser(Lexer* lexer) :
  m_lexer(lexer)
{
}

double Parser::parsePrimaryExpression()
{
    m_lexer->nextToken();

    switch (m_lexer->currentToken())
    {
        case TokenType::Number:
        {
            auto number = m_lexer->getNumber();
            m_lexer->nextToken();
            return number;
        }

        case TokenType::Minus:
            return -parsePrimaryExpression();

        case TokenType::LeftParen:
        {
            auto result = parseAddSub();
            if (m_lexer->currentToken() != TokenType::RightParen)
            {
                qDebug() << "Error: missing brackets.";
                exit(-1);
            }
            m_lexer->nextToken();
            return result;
        }

        default:
            qDebug() << "Error: expected primary expression.";
            exit(-1);
    }
}

double Parser::parseMulDiv()
{
    auto result = parsePrimaryExpression();

    while (true)
    {
        switch (m_lexer->currentToken())
        {
            case TokenType::Multiply:
                result *= parsePrimaryExpression();
                break;

            case TokenType::Divide:
            {
                auto temp = parsePrimaryExpression();
                if (temp != 0.0)
                {
                    result /= temp;
                    break;
                }
                else
                {
                    qDebug() << "Error: division by zero.";
                    exit(-1);
                }
            }

            default:
                return result;
        }
    }
}

double Parser::parseAddSub()
{
    auto result = parseMulDiv();

    while (true)
    {
        switch (m_lexer->currentToken())
        {
            case TokenType::Plus:
                result += parseMulDiv();
                break;

            case TokenType::Minus:
                result -= parseMulDiv();
                break;

            default:
                return result;
        }
    }
}

double Parser::calculate()
{
    return parseAddSub();
}
