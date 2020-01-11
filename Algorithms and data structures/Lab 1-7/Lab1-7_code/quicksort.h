#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <QMainWindow>
#include "sort.h"

class QuickSort : public Sort
{
public:
    QuickSort();
    void sort(std::vector<int> &array);
    void sort(std::vector<int> &array, int start, int end);
};

#endif // QUICKSORT_H
