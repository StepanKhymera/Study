#include "mainwindow.h"
#include "ui_mainwindow.h"

static std::string S_NAMES[6] = {"Bubble", "Select", "Quick", "Shell", "Merge", "Count"};
static std::string sizes[3] = {"1000", "10000", "100000"};


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Chart = new QChart;
    ui->graphicsView->setChart(Chart);
    unsigned long long size = 100;
    for(int i = 0; i < V; ++i){
        vect[i].reserve(size);
        if(V > 3) size+=1000;
        else {
            size*=10;
        }
    }
    Sorts = new Sort*[6];
    Sorts[0] = new BubbleSortF;
    Sorts[1] = new Selectsort;
    Sorts[2] = new QuickSort;
    Sorts[3] = new ShellSort;
    Sorts[4] = new MergeSort;
    Sorts[5] = new CountSort;
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->tableWidget->setEnabled(true);
    double** times = new double*[V];
    for(int i = 0; i < V; ++i){
        times[i] = new double[6];
    }

    QElapsedTimer timer;
    QLineSeries* lines = new QLineSeries[6];

if(GRAPH){
    QChart* Chart;
    Chart = new QChart;
    ui->graphicsView->setChart(Chart);
    QCategoryAxis* size = new QCategoryAxis;
    QCategoryAxis* time = new QCategoryAxis;
    size->setLabelsPosition(QCategoryAxis::AxisLabelsPositionOnValue);
    time->setLabelsPosition(QCategoryAxis::AxisLabelsPositionOnValue);

    time->setStartValue(0);
    time->setMin(0);
    time->setMax(30);
    time->append("1 ms", 1);
    time->append("2 ms", 2);

    size->setStartValue(0);
    size->setMin(0);
    size->setMax(V-1+0.2);
    size->append("1000", 0.1);
    size->append("10000", 1.1);
    size->append("100000", 2.1);

    Chart->addAxis(time, Qt::AlignLeft);
    Chart->addAxis(size, Qt::AlignBottom);

    for(int i =0; i < 6; ++i){
            lines[i].setName(QString::fromStdString(S_NAMES[i]));
            Chart->addSeries(&lines[i]);
            lines[i].attachAxis(size);
            lines[i].attachAxis(time);
            qApp->processEvents();
    }
    lines[5].setColor(QColor(0, 0, 0, 255));
}
    for(int v = 0; v < V; ++v){
        for(int i = 0; i < 6; ++i){

            std::vector<int> run;

            run = vect[v];
            timer.start();
            Sorts[i]->sort(run);
            times[v][i] = timer.nsecsElapsed()/1000000.0;
            std::fstream out(S_NAMES[i]+ '_'+ sizes[v] + "_result.txt", std::fstream::out|std::fstream::trunc);
            for(unsigned long long j = 0; j < run.size(); ++j){
                out << run[j] << ' ';
            }
            out.close();
            ui->tableWidget->setItem(i,v+1,new QTableWidgetItem(QString::number(times[v][i])+" ms"));
            if(GRAPH) lines[i].append( v+(1)/10.0, toChartTime(times[v][i]));
            qApp->processEvents();
        }
    }
    Time_Out(times);

}

void MainWindow::on_pushButton_2_clicked()
{
    if(!RANDOM){
       std::fstream tims("tims.txt", std::fstream::in);
       std::vector<int> generate;
       int sum = 0;
       int temp;
       generate.reserve(vect[0].capacity());
       for(int i =0; i < vect[0].capacity(); ++i){
            tims >> temp;
            sum += temp;
           generate.push_back(temp);
       }
       vect[0] = generate;
       tims.close();
       std::cout << sum;

    } else {

   QRandomGenerator gen(QDateTime::currentSecsSinceEpoch());
   int temp;
   for(int v = 0; v < V; ++v){
       std::ostringstream s;
       std::vector<int> generate;

       generate.reserve(vect[v].capacity());
       for(int i =0; i < vect[v].capacity(); ++i){
               temp = gen.bounded(-1000, 1001);
               generate.push_back(temp);
               s << temp <<' ';
       }
//       tims.close();
       std::fstream out("input_" +sizes[v] +".txt", std::fstream::out|std::fstream::trunc);
       out << s.str();
       out.close();
       vect[v] = generate;

    }
    }
   ui->pushButton->setEnabled(true);
   ui->pushButton_4->setEnabled(true);
   if(V>=2)ui->pushButton_5->setEnabled(true);
   if(V==3)ui->pushButton_6->setEnabled(true);
}



double toChartTime(double time){
    if (time <= 5)
        return time;
    if (time <= 10)
        return ((time-5)*2)/5.0 + 5;

    else if (time <= 50)
        return ((time-10)*2.5)/40.0 + 7 ;

    else if (time <= 100)
        return ((time-50)*2.5)/50.0 + 9.5;

    else if (time <= 1000)
        return ((time-100)*6)/900.0 + 12;

    else if (time <= 10000)
        return ((time-1000)*3)/9000.0 + 18;

    else if (time <= 100000)
        return ((time-10000)*6)/90000.0 + 21;
    else
        return 30;
}

void Time_Out(double** times){
    std::fstream out("Times.txt", std::fstream::out|std::fstream::app);
    for(int i = 0 ; i < V; ++i){
        for(int j =0 ; j < 6; ++j){
            out << times[i][j] << '\t';
        }
        out<<'\n';
    }
    out<<"\n\n\n\n\n";
    out.close();
}


#define FONT 11
#define W 800
#define H 300

void MainWindow::on_pushButton_4_clicked()
{
    QFile file("input_1000.txt");
    file.open(QIODevice::ReadOnly);
    QTextBrowser * b = new QTextBrowser;
    b->resize(W, H);
    b->setFontPointSize(FONT);
    b->setText(file.readAll());
    b->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    QFile file("input_10000.txt");
    file.open(QIODevice::ReadOnly);
    QTextBrowser * b = new QTextBrowser;
    b->resize(W, H);
    b->setFontPointSize(FONT);
    b->setText(file.readAll());
    b->show();
}

void MainWindow::on_pushButton_6_clicked()
{
    QFile file("input_100000.txt");
    file.open(QIODevice::ReadOnly);
    QTextBrowser * b = new QTextBrowser;
    b->resize(W, H);
    b->setFontPointSize(FONT);
    b->setText(file.readAll());
    b->show();
}

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{

    QFile file( QString::fromStdString(S_NAMES[row])+"_"+ QString::fromStdString(sizes[column-1]) +"_result"+  ".txt");
    file.open(QIODevice::ReadOnly);
    QTextBrowser * b = new QTextBrowser;
    b->resize(W, H);
    b->setFontPointSize(FONT);
    b->setText(file.readAll());
    b->show();
}

void MainWindow::on_pushButton_3_clicked()//238
{
    std::string read;
    int rand;
    QString output;
    QRandomGenerator gen(QDateTime::currentSecsSinceEpoch());
    std::fstream fs("C:\\Users\\Nout\\Documents\\build-Lab1_ASD-Desktop_Qt_5_12_1_MinGW_64_bit-Debug\\Cities.txt", std::ifstream::in);
    for(int i = 0; i <69; ++i){
        rand = gen.bounded(15);
        for(int j =0; j < rand; ++j){
            fs.ignore(50, '\n');
            if(fs.eof()){
                fs.seekg(0);
            }
        }
        fs >> read;
        output.append(QString::fromStdString(read)+' ');
    }
    fs.close();
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

double* InputArr(QString* input, int array_size){
        double* unsorted_array = new  double[array_size];
        double read;
        std::istringstream s(input->toStdString());
        for(int i = 0; i < array_size; ++i){
            s >> read;
            unsorted_array[i] = read;
        }
        return unsorted_array;
}

void Modify(double* arr, int size){

    for(int i = 0 ; i < size; ++i){
        if(static_cast<int>(arr[i])%2==0){
            arr[i] = tan(arr[i]) - arr[i];
            arr[i]*=10;
            arr[i]=round(arr[i]);
            arr[i]/=10;
        } else {
            arr[i] = fabs(arr[i]);
        }
    }
}

void ToINT(double* arr, int size){
    for(int i = 0 ; i < size; ++i){
        arr[i] *= 10;
    }

}
