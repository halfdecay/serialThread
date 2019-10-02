#include "serialmainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SerialMainWindow w;
    w.show();
    return a.exec();
}
