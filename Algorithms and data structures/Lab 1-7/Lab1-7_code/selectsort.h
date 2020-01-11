#ifndef SELECTSORT_H
#define SELECTSORT_H

#include <QMainWindow>
#include <sort.h>

class Selectsort : public Sort
{
public:
    Selectsort();
    void sort(std::vector<int> &array);
};

#endif // SELECTSORT_H
