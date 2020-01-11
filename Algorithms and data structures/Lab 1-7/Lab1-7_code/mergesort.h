#ifndef MERGESORT_H
#define MERGESORT_H

#include <QMainWindow>
#include "sort.h"

class MergeSort : public Sort
{
public:
    MergeSort();
    void sort(std::vector<int> &array);
    void sort(std::vector<int> &array, int left, int right);
    void Merge(std::vector<int> &array, int left,int middle, int right);
};

#endif // MERGESORT_H
