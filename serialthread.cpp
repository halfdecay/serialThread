#include "serialthread.h"
#include <QDebug>

SerialThread::SerialThread(QObject *parent) : QObject(parent), m_dataSerial("")
{

}

bool SerialThread::Running() const
{
    return m_Running;
}

QString SerialThread::dataSerial() const
{
    return m_dataSerial;
}

void SerialThread::runSerial()
{
    count = 0;
    while (m_Running) {
        count++;
        m_dataSerial = count;
        emit sendSerialData(m_dataSerial);
        qDebug()<<count;


    }
    emit finishedSerial();
}

void SerialThread::setRunning(bool Running){
    if (m_Running == Running)
        return;
    m_Running = Running;
    emit RunningChanged(m_Running);
}

void SerialThread::setdataSerial(QString dataSerial)
{
    if (m_dataSerial == dataSerial)
        return;

    m_dataSerial = dataSerial;
    emit dataSerialChanged(m_dataSerial);
}
