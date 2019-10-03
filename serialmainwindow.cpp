#include "serialmainwindow.h"
#include "ui_serialmainwindow.h"

SerialMainWindow::SerialMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SerialMainWindow)
{
    ui->setupUi(this);
    connect(&serialthread,&QThread::started,&SerialStepperThread,&SerialThread::runSerial);// Запуск выполнения метода run будет осуществляться по сигналу запуска от соответствующего потока
    connect(&SerialStepperThread,&SerialThread::finishedSerial,&serialthread,&QThread::terminate);  // Остановка потока же будет выполняться по сигналу finished от соответствующего объекта в потоке
    connect(&SerialStepperThread,&SerialThread::sendSerialData,this,&SerialMainWindow::labelViewer);
    SerialStepperThread.moveToThread(&serialthread);
}

SerialMainWindow::~SerialMainWindow()
{
    delete ui;
}

void SerialMainWindow::labelViewer()
{
    QString resp = SerialStepperThread.dataSerial();
    ui->label->setText(resp);
}



void SerialMainWindow::on_pushButton_clicked()
{
    SerialStepperThread.setRunning(true);
    serialthread.start();
}

void SerialMainWindow::on_pushButton_2_clicked()
{
    SerialStepperThread.setRunning(false);
}
