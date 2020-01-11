#ifndef LINESEARCH_H
#define LINESEARCH_H
#include <QMainWindow>
#include <iostream>
#include <sstream>
class LineSearch
{
    QString* res;
public:
    LineSearch(QString* str);
    QString search(const std::vector<int> &a);

};

#endif // LINESEARCH_H
