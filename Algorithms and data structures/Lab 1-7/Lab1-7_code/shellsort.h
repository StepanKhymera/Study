#ifndef SHELLSORT_H
#define SHELLSORT_H

#include <QMainWindow>
#include <sort.h>

class ShellSort : public Sort
{
public:
    ShellSort();
    int sort(float** matr, int a, int b);
    void sort(std::vector<int> &array);
    int getNum() const;
};

#endif // SHELLSORT_H
