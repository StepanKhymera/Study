#include "bubblesort.h"

BubbleSort::BubbleSort( QString* output_)
{
    output = output_;
}
int BubbleSort::sort(int* array, int size){
    int temp;
    QElapsedTimer timer;
    timer.start();
    for (int i = 0; i < size; ++i) {
        for(int j = 0; j < size-1; ++j){
            if(array[j] > array[j+1]){
                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }

        }
        output->append(QString::number(i+1) + ") ");
        for(int i =0; i < size; ++i){
            output->append(QString::number(array[i]) + ' ');
        }
        output->append('\n');
    }
    return timer.nsecsElapsed();
}

