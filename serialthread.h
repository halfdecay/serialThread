#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H

#include <QObject>

class SerialThread : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool Running READ Running WRITE setRunning NOTIFY RunningChanged)
    Q_PROPERTY(QString dataSerial READ dataSerial WRITE setDataSerial NOTIFY dataSerialChanged)
    bool m_Running;
    QString m_dataSerial;
    QString m_dataSerialRev;
    int count;

public:
    explicit SerialThread(QObject *parent = nullptr);

    bool Running() const;

    QString dataSerial() const;

signals:

    void finishedSerial();
    void RunningChanged(bool Running);
    void dataSerialChanged(QString dataSerial);
    void sendSerialData(QString dataSerrialRev);

public slots:

    void runSerial();
    void setRunning(bool Running);
    void setdataSerial(QString dataSerial);
};

#endif // SERIALTHREAD_H
