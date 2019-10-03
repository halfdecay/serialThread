#include "serialmainwindow.h"
#include "ui_serialmainwindow.h"
#include "settingsdialog.h"

#include <QLabel>
#include <QMessageBox>

SerialMainWindow::SerialMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SerialMainWindow),
      m_settings(new SettingsDialog),

      m_serial(new QSerialPort(this))

{
    ui->setupUi(this);
    connect(&serialthread,&QThread::started,&SerialStepperThread,&SerialThread::runSerial);// Запуск выполнения метода run будет осуществляться по сигналу запуска от соответствующего потока
    connect(&SerialStepperThread,&SerialThread::finishedSerial,&serialthread,&QThread::terminate);  // Остановка потока же будет выполняться по сигналу finished от соответствующего объекта в потоке
    connect(&SerialStepperThread,&SerialThread::sendSerialData,this,&SerialMainWindow::labelViewer);
    SerialStepperThread.moveToThread(&serialthread);
    connect(ui->actionConfigure, &QPushButton::clicked , m_settings, &SettingsDialog::show);
}

SerialMainWindow::~SerialMainWindow()
{
    delete ui;
    delete m_settings;
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

void SerialMainWindow::on_actionConfigure_clicked()
{

}
