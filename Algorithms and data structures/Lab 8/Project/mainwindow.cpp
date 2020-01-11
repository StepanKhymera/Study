#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>
#include <QDateTime>
#include <sstream>
#include <fstream>

#include "linesearch.h"

#define V 5
static std::string sizes[V];

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    unsigned long long size = ui->textEdit_2->toPlainText().toInt();

    QRandomGenerator gen(QDateTime::currentSecsSinceEpoch());
    int temp;
    std::vector<int> generate;

        std::ostringstream s;
        vect.clear();
        vect.reserve(size);
        generate.reserve(size);
        for(int i =0; i < size; ++i){
                temp = gen.bounded(-100, 101);
                generate.push_back(temp);
                s << temp <<' ';
       }
        ui->textEdit->setText(QString::fromStdString(s.str()));
}


void MainWindow::on_pushButton_2_clicked()
{
    QString input = ui->textEdit->toPlainText();

    int read, size = ArrSize(&input);
    vect.clear();
    std::istringstream s(ui->textEdit->toPlainText().toStdString());
    for(int i = 0; i <  size; ++i){
        s >> read;
        vect.push_back(read);
    }
    QString steps, result;
    LineSearch Search(&steps);
    result = Search.search(vect);
    ui->textEdit_3->setText(steps);
    ui->textEdit_4->setText(result);

}


#define FONT 11
#define W 800
#define H 300

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    QString path;
    if(column == 2){
        return;
    }
    if(column == 0){
        path =  QString::fromStdString(sizes[row]);
        path.append("_input.txt");
    } else if(column == 1){
        path =  QString::fromStdString(sizes[row]) + "_result.txt";
    }
//    QProcess::startDetached(path);
    std::string cons = path.toStdString();
    system(cons.c_str());
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
