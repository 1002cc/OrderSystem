#include "server.h"

#include <QByteArray>
#include <QString>

server::server(int port)
{
    this->listen(QHostAddress::Any,port);
    connect(this, &server::newConnection, this, &server::incomingConnection);
}

void server::incomingConnection()
{ 
    while (this->hasPendingConnections())
   {
        QTcpSocket *socket = this->nextPendingConnection();   //拿到当前的socket
        m_clientList.append(socket);    //将当前socket添加到列表中（方便操作）
        connect(socket,SIGNAL(readyRead()),this,SLOT(receiveMessage()));
   }
}

void server::receiveMessage()
{
    QTcpSocket *curClient = dynamic_cast<QTcpSocket *>(sender());
    emit giveMsg(curClient->readAll());
}









