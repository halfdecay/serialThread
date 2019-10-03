#ifndef SERIALMAINWINDOW_H
#define SERIALMAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QtSerialPort/QSerialPort>
//#include <serialthread.h>
#include <serialThread/serialthread.h>
#include <settingsdialog.h>

QT_BEGIN_NAMESPACE
namespace Ui { class SerialMainWindow; }
QT_END_NAMESPACE

class SettingsDialog;

class SerialMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    SerialMainWindow(QWidget *parent = nullptr);
    ~SerialMainWindow();
    void labelViewer();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_actionConfigure_clicked();

private:
    Ui::SerialMainWindow *ui;
    QThread serialthread;
    SerialThread SerialStepperThread;
    SettingsDialog *m_settings = nullptr;
    QSerialPort *m_serial = nullptr;
};
#endif // SERIALMAINWINDOW_H
