#include "serverthread.h"
#include "module.h"

serverThread::serverThread(int sockDesc,int c_time, int stime,QObject *parent) :
    QThread(parent),
    m_sockDesc(sockDesc)
{
    curruent_time=c_time;
    starttime=stime;
}

serverThread::~serverThread()
{
    m_socket->close();
}
void serverThread::sendtoall(const QByteArray&data){
    emit sendData(m_sockDesc,data);
}

void serverThread::run(void)
{
    m_socket = new MySocket(m_sockDesc);
    mol=new Module();
    if (!m_socket->setSocketDescriptor(m_sockDesc)) {
        return ;
    }
    connect(m_socket, &MySocket::disconnected, this, &serverThread::disconnectToHost);
    connect(m_socket, SIGNAL(dataReady(const QString&, const QByteArray&)),
            this, SLOT(recvDataSlot(const QString&, const QByteArray&)));
    connect(this, SIGNAL(sendData(int, const QByteArray&)),
            m_socket, SLOT(sendData(int, const QByteArray&)));
    connect(mol,SIGNAL(datasend(int , const QByteArray &)),m_socket,SLOT(sendData(int , const QByteArray&)));
    QString tempQ="link "+QString::number(curruent_time)+" "+QString::number(starttime)+" "+QString::number(m_sockDesc)+" ";
    emit sendData(m_sockDesc,tempQ.toLatin1());
    this->exec();
}
void serverThread::sendDataSlot(int sockDesc, const QByteArray &data)
{
    if (data.isEmpty()) {
        return ;
    }
    emit sendData(sockDesc, data);
}

void serverThread::recvDataSlot(const QString &ip, const QByteArray &data)
{
    mol->molstart(m_sockDesc,data);
}

void serverThread::disconnectToHost(void)
{
    emit disconnectTCP(m_sockDesc);
    m_socket->disconnectFromHost();
}

/*void serverThread::updatetime(){
    curruent_time++;
    curruent_time=(curruent_time+24)%24;
}*/
