#ifndef BUBBLESORTF_H
#define BUBBLESORTF_H

#include <QMainWindow>
#include <QElapsedTimer>
#include <sort.h>


class BubbleSortF : public Sort
{
private:

public:
    BubbleSortF (QString* output, int* counter);
    BubbleSortF();
    void sort(std::vector<int> &array);
    void swap(int* a, int* b);
};

#endif // BUBBLESORTF_H
