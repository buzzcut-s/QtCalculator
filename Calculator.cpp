#include "Calculator.h"

#include "Lexer.h"
#include "Parser.h"

Calculator::Calculator(QObject* parent) :
  QObject{parent}
{
}

QString Calculator::getOutputBuffer() const
{
    return outputBuffer;
}

void Calculator::setOutputBuffer(const QString& input)
{
    outputBuffer = input;
    emit outputBufferChanged();
}

static bool isOperator(const QString& input)
{
    return input == "/" || input == "*" || input == "+" || input == "-";
}

static bool isOperator(QCharRef input)
{
    return input == "/" || input == "*" || input == "+" || input == "-";
}

void Calculator::process(const QString& input)
{
    static auto lexer  = Lexer();
    static auto parser = Parser(&lexer);

    if (input == "C")
    {
        outputBuffer.clear();
        m_overwriteBuffer = true;
    }
    else if (input == "←")
    {
        outputBuffer.chop(1);
        m_overwriteBuffer = false;
    }
    else if (isOperator(input))
    {
        m_overwriteBuffer = false;
        if (outputBuffer.isEmpty() && input == "-")
        {
            outputBuffer += input;
        }
        else if (outputBuffer.isEmpty() || outputBuffer.back() == input)
        {
            return;
        }
        else
        {
            if (isOperator(outputBuffer.back()))
            {
                if (outputBuffer.back() == "-" && outputBuffer.size() == 1)
                    return;
                outputBuffer.chop(1);
            }
            outputBuffer += input;
        }
    }
    else if (input == "=")
    {
        if (!outputBuffer.isEmpty())
        {
            lexer.setExpression(outputBuffer);
            outputBuffer = QString::number(parser.calculate());

            m_history.push_back(outputBuffer);
            m_historyIdx = m_history.size() - 1;
        }
        m_overwriteBuffer = true;
    }
    else if (input == "↓")
    {
        if (m_historyIdx + 1 < m_history.size())
        {
            outputBuffer      = m_history[++m_historyIdx];
            m_overwriteBuffer = true;
        }
    }
    else if (input == "↑")
    {
        if (m_historyIdx - 1 >= 0)
        {
            outputBuffer      = m_history[--m_historyIdx];
            m_overwriteBuffer = true;
        }
    }
    else
    {
        if (input == "." && !outputBuffer.isEmpty()
            && (outputBuffer.back() == "." || isOperator(outputBuffer.back())))
        {
            return;
        }
        if (m_overwriteBuffer)
        {
            outputBuffer = input;
        }
        else
        {
            outputBuffer += input;
        }
        m_overwriteBuffer = false;
    }

    emit outputBufferChanged();
}
