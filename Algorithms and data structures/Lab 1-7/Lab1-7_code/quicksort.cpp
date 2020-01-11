#include "quicksort.h"

QuickSort::QuickSort(){

}

void QuickSort::sort(std::vector<int> &array){
    sort(array, 0, array.size()-1);
}

void QuickSort::sort(std::vector<int> &array, int start, int end){
    int i, j, size = array.size()-1;
    i =  start;
    j = end;
   int run = array[i], temp;
   while(i <= j){
        while(array[i] < run) ++i;

        while(array[j] > run)
            --j;

        if(i <= j){
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            ++i;
            --j;
        }
        if(isOutEnbl){
            ++(*counter);
            output->append(QString::number((*counter)++) + ") ");
            for(unsigned long long l =0; l < size; l++){
                output->append(QString::number(array[l]) + ' ');
            }
            output->append('\n');
        }
   }
   if(i < end){
       sort(array, i, end);
   }
   if(j > start) {
       sort(array, start, j);
   }
}
