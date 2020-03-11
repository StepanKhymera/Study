#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>


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
    Lexer lexer;
//    ui->textEdit_2->setText(lexer.BREAK_DOWN(ui->textEdit->toPlainText()));
    QList<QStandardItem*> list;
    QStandardItem* row = new QStandardItem("row");

    row->appendRow(new QStandardItem("3"));
    row->appendRow(new QStandardItem("2"));

    list.push_back(row);
    model.appendRow(list);
    ui->treeView->setModel(&model);

}
