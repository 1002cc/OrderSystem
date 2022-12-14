#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class server :public QTcpServer
{
    Q_OBJECT
public:
    server();
    server(int port);
    void incomingConnection();
private:
    QList<QTcpSocket *> m_clientList;
private slots:
    void receiveMessage();

signals:
    void giveMsg(QString);
};

#endif // SERVER_H
