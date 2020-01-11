#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <QMainWindow>

 class Sort
{
protected:
    QString* output;
    int* counter;
    bool isOutEnbl = false;
public:
    Sort();
    Sort(QString* output_, int* counter_);
    virtual void sort(std::vector<int> &array) = 0;
    virtual ~Sort();
};

#endif // SORT_H
