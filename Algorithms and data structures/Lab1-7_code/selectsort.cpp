#include "selectsort.h"

Selectsort::Selectsort(){

}


void Selectsort::sort(std::vector<int> &array){
    int temp, min, size = array.size();

    for (int i = 0; i < size-1; ++i) {
        min = i+1;
        for(int j = i+1; j < size; ++j){
            if(array[min] > array[j]){
                min = j;
            }
        }
        if(array[min] < array[i]){
            temp = array[min];
            array[min] = array[i];
            array[i] = temp;
        }
        if(isOutEnbl){
            output->append(QString::number(i+1) + ") ");
            for(int i =0; i < size; ++i){
                output->append(QString::number(array[i]) + ' ');
            }
            output->append('\n');
        }
    }
}
