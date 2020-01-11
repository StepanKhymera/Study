#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>
#include <QDateTime>
#include <sstream>
#include <fstream>
#include <QList>

#include "binarysearch.h"
#include "quicksort.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setColumnWidth(0, 30);
    ui->tableWidget->setColumnWidth(1, 140);
    ui->tableWidget->setColumnWidth(2, 35);
    ui->tableWidget->setColumnWidth(3, 50);

    ui->tableWidget_2->setColumnWidth(0, 30);
    ui->tableWidget_2->setColumnWidth(1, 140);
    ui->tableWidget_2->setColumnWidth(2, 35);
    ui->tableWidget_2->setColumnWidth(3, 50);

    ui->tableWidget_3->setColumnWidth(0, 30);
    ui->tableWidget_3->setColumnWidth(1, 140);
    ui->tableWidget_3->setColumnWidth(2, 35);
    ui->tableWidget_3->setColumnWidth(3, 50);
}

MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::on_pushButton_clicked()
{

    char* read = new char[50];
    int rand;
    QString output;
    QRandomGenerator gen(QDateTime::currentSecsSinceEpoch());
    std::fstream fs("Names.txt", std::ifstream::in);
    ui->tableWidget->setRowCount(ui->textEdit_2->toPlainText().toInt());
    for(int i = 0; i < ui->textEdit_2->toPlainText().toInt(); ++i){
        rand = gen.bounded(15);
        for(int j =0; j < rand; ++j){
            fs.ignore(50, '\n');
            if(fs.eof()){
                fs.seekg(0);
            }
        }
        fs.getline(read , 50, '\n');
        if(fs.eof()){
            fs.seekg(0);
        }
        ui->tableWidget->setItem(i,0, new QTableWidgetItem(QString::number(i+1)));
        ui->tableWidget->setItem(i,1, new QTableWidgetItem(QString::fromStdString(read)));
        ui->tableWidget->setItem(i,2, new QTableWidgetItem(QString::number(gen.bounded(7, 17))));
        ui->tableWidget->setItem(i,3, new QTableWidgetItem(QString::number(gen.bounded(110, 180))));
    }
    fs.close();
    delete[] read;
}

void MainWindow::on_pushButton_2_clicked()
{
    QList<Student> list;
    Student run;
    for(int i = 14; i < ui->textEdit_2->toPlainText().toInt(); ++i){
        run.indx = ui->tableWidget->item(i, 0)->text().toInt();
        run.name = ui->tableWidget->item(i, 1)->text();
        run.age = ui->tableWidget->item(i, 2)->text().toInt();
        run.h = ui->tableWidget->item(i, 3)->text().toInt();
        list.push_back(run);
    }
    QList<Student> inputList = list;

    QString steps, numline;
    std::ostringstream out;
    std::vector<int> indx;
    int iterations, num = 0, first;
    BinarySearch Search(&out, &num, &iterations);
    Search.sort(list, 0, list.size()-1);
    ui->tableWidget_3->setRowCount(ui->textEdit_2->toPlainText().toInt()-14);
    for(int i = 0; i < ui->textEdit_2->toPlainText().toInt()-14; ++i){
        ui->tableWidget_3->setItem(i,0, new QTableWidgetItem(QString::number(i+15)));
        ui->tableWidget_3->setItem(i,1, new QTableWidgetItem((list[i].name)));
        ui->tableWidget_3->setItem(i,2, new QTableWidgetItem(QString::number(list[i].age)));
        ui->tableWidget_3->setItem(i,3, new QTableWidgetItem(QString::number(list[i].h)));
    }



    first = Search.search(list, ui->textEdit_3->toPlainText().toInt());
    ui->textEdit->setText(QString::fromStdString(out.str()));
    if (num){
        ui->textEdit->append("Кількість учнів із заданою висотою: " + QString::number(num));
        for(int i = 1; i <= num; ++i){
            numline.append(QString::number(first+i+15) + ' ');
        }
        ui->textEdit->append("Індекси в посортованому масиві: " + numline);
        numline = "";
        for(int i = 0; i < num; ++i){
            for(int j = 0; j < list.size(); ++j){
                if (inputList[j] == list[first+i]){
                    numline.append(QString::number(j+16) + ' ');
                    vect.push_back(j+15);
                }
            }
        }
        ui->textEdit->append("Індекси у заданому масиві: " + numline);
    }else {
        ui->textEdit->append("Учнів із заданою висотою не знайдено\n");
    }
    ui->textEdit->append("Ітерацій: "+QString::number(iterations-1));
    ui->tableWidget_2->setRowCount(num);
    for(int i = 0; i < num; ++i){
        ui->tableWidget_2->setItem(i,0, new QTableWidgetItem(QString::number(list[first+i].indx)));
        ui->tableWidget_2->setItem(i,1, new QTableWidgetItem((list[first+i].name)));
        ui->tableWidget_2->setItem(i,2, new QTableWidgetItem(QString::number(list[first+i].age)));
        ui->tableWidget_2->setItem(i,3, new QTableWidgetItem(QString::number(list[first+i].h)));
    }
}

int ArrSize(QString* array){
    double read;
    int array_size = 0;
    std::istringstream f(array->toStdString());// визначення розміру вхідного масиву
    while(!(f.eof())){
        f >> read;
        ++array_size;
    }
    return array_size-1;
}
