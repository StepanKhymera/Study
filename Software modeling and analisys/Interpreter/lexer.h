#ifndef LEXER_H
#define LEXER_H

#include <QMainWindow>

#include "token.h"

class Lexer
{
private:
    QVector<QVector<Token*>> *tokens;
public:
    Lexer();
    QString BREAK_DOWN(QString data);
};

#endif // LEXER_H
