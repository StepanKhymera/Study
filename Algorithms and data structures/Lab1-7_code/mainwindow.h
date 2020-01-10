#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <sstream>


#include <QRandomGenerator>
#include <QDateTime>
#include <iostream>
#include <fstream>
#include <QLineSeries>
//#include <QChart>
#include <QChartView>
#include <QValueAxis>
#include <QFile>
#include <QTextBrowser>
#include <QCategoryAxis>

#include <sort.h>
#include <bubblesort.h>
#include <bubblesortf.h>
#include <selectsort.h>
#include <quicksort.h>
#include <shellsort.h>
#include <mergesort.h>
#include <countsort.h>

using namespace QtCharts;
QT_CHARTS_USE_NAMESPACE;
double toChartTime(double time);
#define V 1
#define RANDOM 0
#define GRAPH 0

//int Filter(QString* input, int* unsorted_array);
double* InputArr(QString* input, int array_size);
int ArrSize(QString* array);
void Modify(double* arr, int size);
void ToINT(double* arr, int size);
void Time_Out(double** times);
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    std::string* Generate(int size);
    QChart* Chart;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_tableWidget_cellClicked(int row, int column);

private:
    std::vector<int> vect[V];
    Sort** Sorts;
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
