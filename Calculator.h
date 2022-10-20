#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>

class Calculator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString outputBuffer READ getOutputBuffer WRITE setOutputBuffer NOTIFY outputBufferChanged)

public:
    explicit Calculator(QObject* parent = nullptr);

    QString getOutputBuffer() const;
    void    setOutputBuffer(const QString& input);

    Q_INVOKABLE void process(const QString& input);

signals:
    void outputBufferChanged();

private:
    QString outputBuffer;
};

#endif  // CALCULATOR_H
