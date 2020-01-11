#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H
#include <iostream>
#include <QMainWindow>
#include <sstream>
#include <QList>

typedef struct s{
   int indx;
   QString name;
   int age;
   int h;
   bool operator==(const struct s &value);
} Student;


class BinarySearch
{
    std::ostringstream* out;
    int* num;
    int* iter;
public:
    void sort(QList<Student> &list, int start, int end);
    BinarySearch(std::ostringstream* out, int* num, int* iter);
    int search(QList<Student> &list, int height);
};

#endif // BINARYSEARCH_H
