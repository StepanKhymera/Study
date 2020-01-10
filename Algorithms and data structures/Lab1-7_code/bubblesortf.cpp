#include "bubblesortf.h"

BubbleSortF::BubbleSortF()
{

}

void BubbleSortF::sort(std::vector<int> &array){
    unsigned long long temp, size = array.size();
    bool flag;
    for (unsigned long long i = 0; i < size-1; ++i) {
        flag = true;
        for(unsigned long long j = 0; j < size-i; ++j){
            if(array[j] > array[j+1]){
                flag = false;
                swap(&array[j], &array[j+1]);
            }
        }
//        if(isOutEnbl){
//            ++(*counter);
//            output->append(QString::number(i+1) + ") ");
//            for(int i =0; i < size; ++i){
//                output->append(QString::number(array[i]) + ' ');
//            }
//            output->append('\n');
//        }
        if(flag) break;
    }
}

void BubbleSortF::swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
