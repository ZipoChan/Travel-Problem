#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H
#include "common.h"
#include "module.h"
#include "mysocket.h"
#include <QThread>

class serverThread : public QThread
{
    Q_OBJECT
public:
    serverThread(int sockDesc,int c_time=0,int s_time=0, QObject *parent = Q_NULLPTR);
    ~serverThread();

private:
    void run(void);

public slots:
    void sendDataSlot(int sockDesc, const QByteArray &data);
    void sendtoall(const QByteArray &data);
   // void updatetime();

signals:
    void sendall(const QByteArray &data);
    void dataReady(const QString &ip, const QByteArray &data);
    void sendData(int sockDesc, const QByteArray &data);
    void disconnectTCP(int sockDesc);
    void sendto(const QByteArray &,int );


private slots:
    void recvDataSlot(const QString &ip, const QByteArray &data);
    void disconnectToHost(void);

private:
    int starttime;
    MySocket *m_socket;
    Module *mol;
    int curruent_time;
    int m_sockDesc;
};

#endif // SERVERTHREAD_H
