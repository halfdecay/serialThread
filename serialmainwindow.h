#ifndef SERIALMAINWINDOW_H
#define SERIALMAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <serialthread.h>

QT_BEGIN_NAMESPACE
namespace Ui { class SerialMainWindow; }
QT_END_NAMESPACE

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

private:
    Ui::SerialMainWindow *ui;
    QThread serialthread;
    SerialThread SerialStepperThread;
};
#endif // SERIALMAINWINDOW_H
