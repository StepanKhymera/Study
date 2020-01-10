#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <QMainWindow>
#include <QElapsedTimer>
class BubbleSort
{
private:
    QString* output;
public:
    int time;
    BubbleSort(QString* output);
    int sort(int* array, int size);
    void swap(int* a,int*b);
};
#endif // BUBBLESORT_H
