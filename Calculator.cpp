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

void Calculator::process(const QString& input)
{
    static auto lexer  = Lexer();
    static auto parser = Parser(&lexer);

    if (input == "C")
    {
        outputBuffer.clear();
    }
    else if (input == "<-")
    {
        outputBuffer.chop(1);
    }
    else if (input == "=")
    {
        if (!outputBuffer.isEmpty())
        {
            lexer.setExpression(outputBuffer);
            outputBuffer = QString::number(parser.calculate());
        }
    }
    else
    {
        outputBuffer += input;
    }

    emit outputBufferChanged();
}