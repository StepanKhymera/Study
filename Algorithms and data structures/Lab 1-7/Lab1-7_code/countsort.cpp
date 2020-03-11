#include <math.h>
#include "countsort.h"

CountSort::CountSort()
{

}

void CountSort::sort(std::vector<int> &arr){

    int max= arr[0], min = arr[0], size = arr.size();
    for(int i = 0; i < size; ++i){
        if(arr[i] > max){
            max = arr[i];
        }
        if(arr[i]<min){
            min = arr[i];
        }
    }

    size_t indx_size = (max-min)+1;
    int* indx = new int[indx_size];
    memset(indx,0,indx_size*sizeof (int));

    QString temp = "";
    if(isOutEnbl){
        output->append("   ");
        for(int i = min; i <= max; ++i){
            temp = (QString::number(i/10.0)+' ');
            temp.resize(5, ' ');
            output->append(temp);
        }
        output->append('\n');
    }

    for(int i = 0; i < size; ++i){
        ++indx[static_cast<int>(arr[i] + fabs(min) )];
        if(isOutEnbl){
            output->append(QString::number((*counter)++)+") ");
            for(int j = 0; j < indx_size; ++j ){
                temp = (QString::number(indx[j]));
                temp.resize(5, ' ');
                output->append(temp);
            }
            output->append('\n');
        }
    }

    for(int i = min, j = 0; i <= max; ++i){
        while((indx[i + static_cast<int>(fabs(min))]--)>0){
            arr[j++] = i;

        }
    }

}
