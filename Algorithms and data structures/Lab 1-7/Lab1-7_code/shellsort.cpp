#include "shellsort.h"

ShellSort::ShellSort(){

}

void ShellSort::sort(std::vector<int> &array) // одновимірний масив
{
    int temp, min, size = array.size();
    for(int d = size/2; d; d/=2){
        if(isOutEnbl)
        output->append("d ="+QString::number(d)+'\n');
        for(int i = 0; i < d; i++){
            for(int j = i; j+ d < size; j += d){

                min = j+d;
                for(int k = j+d; k < size; k+=d){
                    if(array[min] > array[k]){
                        min = k;
                    }
                }

                if(array[min] < array[j]){
                    temp = array[min];
                    array[min] = array[j];
                    array[j] = temp;
                }

                if(isOutEnbl){
                    output->append(QString::number((*counter)++) + ") ");//                вивід |v|
                    for(int l =0; l < size; ++l){
                        if((l==j)||((l== min))){
                        output->append( '['+QString::number(array[l])+ ']' + "  ");
                    } else if((l-j)%d==0){
                        output->append('(' + QString::number(array[l])+ ')' + "  ");
                        } else {
                            output->append(QString::number(array[l]) + "  ");
                        }
                    }
                    output->append('\n');                            //                      |^|
                }
            }
        }
    }
}

int ShellSort::sort(float** matr, int a, int b){ //матриця
    int  min;
    float temp;
    float* array = new float[a];
    for(int i = 0; i < a; ++i){
        array[i] = 0;
        for(int j = 0; j < b; ++j){
        array[i] += matr[i][j];
        }
    }
    int size = a;
    for(int d = size/2; d; d/=2){
        output->append("d = "+QString::number(d)+'\n');
        for(int i = 0; i < d; i++){
            for(int j = i; j+ d < size; j += d){

                min = j+d;
                for(int k = j+d; k < size; k+=d){ // знаходить максимальний
                    if(array[min] > array[k]){
                        min = k;
                    }
                }

                output->append(QString::number((*counter)++) + ")" + '\n');//                вивід |v|
                for(int l = 0; l < a; ++l){
                     output->append("   ");
                     if((l==j)||((l== min))){
                          output->append('[');
                        for(int m = 0; m < b; ++m){
                             output->append(QString::number(matr[l][m]) + " ");
                        }
                     output->append(']');
                     }else if((l-j)%d==0){
                         output->append('(');
                       for(int m = 0; m < b; ++m){
                            output->append(QString::number(matr[l][m]) + " ");
                       }
                    output->append(')');
                     } else {
                         for(int m = 0; m < b; ++m){
                              output->append(QString::number(matr[l][m]) + " ");
                         }
                     }
                        output->append("\n");
                }
                output->append('\n');                            //                           |^|

                if(array[min] < array[j]){  //swap
                    temp = array[min];
                    array[min] = array[j];
                    array[j] = temp;

                    for(int sw = 0; sw < b; ++sw){ // swap рядків матриці
                        temp = matr[min][sw];
                        matr[min][sw] = matr[j][sw];
                        matr[j][sw] = temp;
                    }
                }

            }
        }
    }
    return 0;
}
