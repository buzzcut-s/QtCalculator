#include "Lexer.h"

#include <QChar>
#include <QDebug>

double Lexer::getNumber() const
{
    return m_number;
}

TokenType Lexer::nextToken()
{
    if (m_expression.isEmpty())
        return m_currentToken = TokenType::End;

    QChar ch = m_expression.front();
    m_expression.remove(0, 1);

    switch (ch.cell())
    {
        case '/':
            return m_currentToken = TokenType::Divide;
        case '*':
            return m_currentToken = TokenType::Multiply;
        case '+':
            return m_currentToken = TokenType::Plus;
        case '-':
            return m_currentToken = TokenType::Minus;
        case '(':
            return m_currentToken = TokenType::LeftParen;
        case ')':
            return m_currentToken = TokenType::RightParen;
    }

    QString number = "";
    if (ch.isDigit())
    {
        number += ch;
        while (!m_expression.isEmpty()
               && (m_expression.front().isDigit() || m_expression.front() == '.'))
        {
            number += m_expression.front();
            m_expression.remove(0, 1);
        }

        m_number = number.toDouble();

        return m_currentToken = TokenType::Number;
    }
    else
    {
        qDebug() << "Error: invalid syntax.";
        exit(-1);
    }
}

TokenType Lexer::currentToken() const
{
    return m_currentToken;
}

void Lexer::setExpression(const QString& expression)
{
    m_expression = expression.simplified();
    m_expression.replace(" ", "");
}
