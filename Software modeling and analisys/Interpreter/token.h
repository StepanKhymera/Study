#ifndef TOKEN_H
#define TOKEN_H

#include <QMainWindow>

class Token
{
public:
    QString tag;
    QString value;

    Token(QString lexem);
};
#endif // TOKEN_H
