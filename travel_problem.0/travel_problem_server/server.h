#ifndef SERVER_H
#define SERVER_H
#include "common.h"

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = Q_NULLPTR);
    ~Server();

private:
    void incomingConnection(qintptr sockDesc);

private slots:
    void clientDisconnected(int sockDesc);
    void sendall(const QByteArray &data);
    void updatetime();
    void updatetime2();

signals:
    void sendtoall(const QByteArray&data);
    void update();

private:
    int current_time;
    QTimer *qtr;
    int mh;
    QTimer *qtrm;
    QTime start_time;
    QTime c_time;
    QList<int> m_socketList;
};

#endif // SERVER_H
