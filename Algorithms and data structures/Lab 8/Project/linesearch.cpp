#include "linesearch.h"

LineSearch::LineSearch(QString* str)
{
    res = str;
}

QString LineSearch::search(const std::vector<int> &vec){
    std::ostringstream out;
    int max_indx = 0, iter = 1, num, max;
    *res = "";
    for(unsigned long long j = 0; j < vec.size(); ++j){
        if(vec[max_indx] < vec[j]){
            max_indx = j;
        }
     }
     iter = 1;
     int count = 0;
     std::vector<int> maxs;
     out << "ПОШУК КІЛЬКОСТІ НАЙБІЛЬШИХ:\n";
     for(unsigned long long i = 0; i < vec.size(); ++i){
         out << std::to_string(iter) << ") ";
         for(unsigned long long j = 0; j < vec.size(); ++j){
             if( vec[j] == vec[max_indx] && i == j){
                 out <<'|'<<vec[j]<<"| ";
             } else if(j == i){
                 out <<'('<<vec[j]<<") ";
             } else {
                 out << vec[j]<<' ';
             }
        }
         out <<"перевіряю: " <<i+1  <<".  ";
         if(vec[i]==vec[max_indx]){
             ++count;
             maxs.push_back(i);
             out << "дорівнює максимальному\n\n";
         } else {
             out << "менше за максимальний\n\n";
         }
         ++iter;
     }
    *res = QString::fromStdString(out.str());
     QString data = "Індекс першого максимального: " + QString::number(max_indx+1) +
                  "\nКількість найбільших елементів: "+QString::number(count) + "(індекси: ";
     for(int i = 0; i < maxs.size(); ++i){
         data.append(QString::number(maxs[i]+1)+ ' ');
     }
     data.append(") ");
     data.append("\nКількість ітерацій: " + QString::number(iter-1));
     return data;
}
