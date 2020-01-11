#ifndef COUNTSORT_H
#define COUNTSORT_H

#include <QMainWindow>
#include <sort.h>

class CountSort : public Sort
{

public:
    CountSort();
    void sort(std::vector<int> &arr);
};

#endif // COUNTSORT_H
