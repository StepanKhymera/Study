#include "binarysearch.h"

BinarySearch::BinarySearch( std::ostringstream* steps, int * nNum, int * nIter)
{
    out = steps;
    num = nNum;
    iter = nIter;

}

bool Student::operator==(const Student &value){
    if(this->name == value.name && this->age == value.age && this->h == value.h){
        return true;
    } else {
        return false;
    }
}

int BinarySearch::search(QList<Student> &list, int height){

    int size = list.size(), run = size/2;
    *iter = 1;
    for(int i = 0; list[run].h != height; run = (size-i)/2 + i){
        if( run <= 0 || run == 0 || (size-i)/2 == 0){
            return 0;
        }
        *out << *iter << ") \n";
        ++*iter;
        for(int l = i; l < size; ++l){
            if(l == run) *out << "   ";
            *out << 15 +l << "| "<<list[l].name.toStdString() + " " << list[l].h << "\n";
        }
        if(list[run].h>height){
            size = run;
        } else {
            i = run;
        }
        *out << "Поточний індекс = " << run+16 << '\n';
        *out << "Студент: " << (list[run].name).toStdString() << " | Вік = " << list[run].age << " | Зріст = " << list[run].h << '\n';
        *out << "Зріст не співпав." << "\n";
        if(list[run].h>height){
            *out << "Зріст більший ніж заданий." << "\n";
        } else {
            *out << "Зріст менший ніж заданий." << "\n";
        }
        *out << "Наступний початок масиву: " << i+16 << "\n";
        *out << "Наступний кінець масиву: " << size+14 << "\n";
        *out << "Наступнтий поточний: " << (size-i)/2 + i+16 <<"\n\n";
    }
    *out << *iter << ") ";
    ++*iter;
    *out << "Поточний індекс = " << run+16 << '\n';
    *out << "Студент: " << (list[run].name).toStdString() << " | Вік = " << list[run].age << " | Зріст = " << list[run].h << '\n';
    *out << "Зріст співпав." << "\n\n";
    *num = 1;
    int first;
    for(first = run-1; list[run].h == list[first].h; --first){
        ++(*num);
        if(first <= 0) break;
    }

    for(int i = run+1; list[run].h == list[i].h; ++i){
        ++(*num);
        if(i >= (list.size()-1)) break;
    }
    return first+1;
}

void BinarySearch::sort(QList<Student> &list, int start, int end){
    int i, j;
    i =  start;
    j = end;
   int run = list[i].h;
   while(i <= j){
        while(list[i].h < run) ++i;
        while(list[j].h > run) --j;
        if(i <= j){
              list.swap(i, j);
            ++i;
            --j;
        }
   }
   if(i < end){
       sort(list, i, end);
   }
   if(j > start) {
       sort(list, start, j);
   }
}
