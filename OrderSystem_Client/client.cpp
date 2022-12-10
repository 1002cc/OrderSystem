#include "client.h"
#include <QByteArray>

client::client(QObject *parent) : QObject(parent)
{
    sockent=new QTcpSocket(this);
    sockent->connectToHost("192.168.3.138",8888);
    connect(sockent,SIGNAL(readRead()),this,SLOT(recevieMessage()));
}

void client::sendMessage(const QString &str)
{
    sockent->write(str.toUtf8());
}

void client::recevieMessage()
{
    QByteArray arr=sockent->readAll();
    QString str= arr.data();
}
