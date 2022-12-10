#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include <QTableView>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

#include "land.h"
#include "sql.h"
#include "server.h"
namespace Ui {
class admin;
}

class admin : public QWidget
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    ~admin();

private slots:
    void on_listWidget_currentRowChanged(int currentRow);

    void on_pushButton_ru_clicked();

    void adminGiveMsg(QString);
    void on_tableView_sql_clicked(const QModelIndex &index);

    void on_pushButton_add_clicked();

    void on_pushButton_chang_clicked();

    void on_pushButton_delete_clicked();

private:
    Ui::admin *ui;
    server* server_s;
    QSqlQuery* query;
    QSqlQueryModel* querydel;
    QString textcol;
    QModelIndex indexdel;
};


//读取目录文件保存到数据库中
/*
    //打开资源文件
    flielist data;
    QFileInfoList list_data_c;
    QFileInfoList list_data_h;
    QFileInfoList list_data_y;
    QFileInfo data_c;
    QFileInfo data_h;
    QFileInfo data_y;
    //链表读取文件数据
    list_data_c=data.FindFile(":/c/image/c/");
    list_data_h=data.FindFile(":/h/image/h/");
    list_data_y=data.FindFile(":/y/image/y/");
    int x=20;
    //显示菜品
    for(int i=0;i<list_data_c.size();i++)
    {
      QString username  data_c=list_data_c.at(i);
        wigthshow *mo=new wigthshow(data_c.filePath(),ui->tab_1);
        mo->move(x,30);
        mo->show();
        ins_data(data_c.fileName(),data_c.filePath(),20,20,"茶点","无");
        list_shop_all.append(mo);
        x+=170;
    }
*/


#endif // ADMIN_H
