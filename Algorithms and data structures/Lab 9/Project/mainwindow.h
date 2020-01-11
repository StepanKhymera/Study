#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

int ArrSize(QString* array);

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void GetNames();
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    std::vector<int> vect;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
