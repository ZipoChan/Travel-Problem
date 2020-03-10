#include "server.h"
#include "serverthread.h"

Server::Server(QObject *parent) :
        QTcpServer(parent)
{
    qtr=new QTimer;
    connect(qtr,SIGNAL(timeout()),this,SLOT(updatetime()));
    qtr->start(2000);
    qtrm= new QTimer;
    connect(qtrm,SIGNAL(timeout()),this,SLOT(updatetime2()));
    current_time=0;
    mh=0;
    qtrm->start(5);
}

Server::~Server()
{

}
void Server::updatetime2(){
    mh++;
    mh%=400;
}

void Server::incomingConnection(qintptr sockDesc)
{
    m_socketList.append(sockDesc);

    serverThread *thread = new serverThread(sockDesc,current_time,mh);

    connect(thread, SIGNAL(disconnectTCP(int)), this, SLOT(clientDisconnected(int)));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    connect(thread,SIGNAL(sendall(const QByteArray &)),this,SLOT(sendall(const QByteArray&)));
    connect(this,SIGNAL(sendtoall(const QByteArray &)),thread,SLOT(sendtoall(const QByteArray&)));

   // connect(this,SIGNAL(update()),thread,SLOT(updatetime()));
    thread->start();
}
void Server::clientDisconnected(int sockDesc)
{
    qDebug()<<"disconnected!";
}
void Server::sendall(const QByteArray &data){
    emit sendtoall(data);
}

void Server::updatetime(){
    current_time=(current_time+1+24)%24;
    emit update();
}
