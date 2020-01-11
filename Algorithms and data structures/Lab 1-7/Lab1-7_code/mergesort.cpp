#include "mergesort.h"

MergeSort::MergeSort(){

}

void MergeSort::sort(std::vector<int> &array){
    sort(array, 0, array.size());
}


void MergeSort::sort(std::vector<int> &array, int left, int right){
    if(left < right)
    {
        int middle = (right+left)/2;
        sort(array, left,middle);
        sort(array, middle+1,right);
        Merge(array,left,middle,right);
    }
}

void MergeSort::Merge(std::vector<int> &array, int left,int middle, int right){
    int size = array.size();
    if(isOutEnbl){
        output->append(QString::number((*counter)++) + ") \n");                //OUTPUT  v
        for(int i =0; i < size; ++i){
            if(i == left){
                output->append('|' + QString::number(array[i]) + ' ');
            }else if(i == right){
                output->append( QString::number(array[i])+ '|' + ' ');
            }else{
            output->append(QString::number(array[i]) + ' ');
            }
            if(i == middle){
                output->append("| ");
            }
        }
        output->append('\n');                                             //OUTPUT  v
    }

    int n1 = middle - left + 1;
    int n2 =  right - middle;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; ++i)
        L[i] = array[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = array[middle + 1+ j];

    int i = 0, j = 0, k = left;
    while ((i < n1) && (j < n2))
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            ++i;
        }
        else
        {
            array[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1)
    {
        array[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2)
    {
        array[k] = R[j];
        ++j;
        ++k;
    }
    if(isOutEnbl){
        for(int i =0; i < size; ++i){                                      //OUTPUT  v
            if(i == left){
                output->append('|' + QString::number(array[i]) + ' ');
            }else if(i == right){
                output->append( QString::number(array[i])+ '|' + ' ');
            }else{
            output->append(QString::number(array[i]) + ' ');
            }
        }
        output->append('\n');                                               //OUTPUT  ^
    }

    delete[] L;
    delete[] R;
}
