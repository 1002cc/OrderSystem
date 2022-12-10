#ifndef ORDER_H
#define ORDER_H

#include <QMainWindow>
#include "wigthshow.h"
namespace Ui {
class Order;
}

class Order : public QMainWindow
{
    Q_OBJECT

public:
    explicit Order(QWidget *parent = nullptr);
    ~Order();

    void setusernum(QString usernum);

    void setlistshop(QList<wigthshow*> list_shop_alls);
private slots:
    void on_pushButton_shopping_clicked();

    void on_pushButton_ru_clicked();

    void closeorder();
private:
    struct tcpsenddata
    {
        QString name; //名称
        int count;    //数量
         int money;     //总计
        QString notes;//备注
    };

    Ui::Order *ui;
    int sum;
    QString usernum;
    QList<wigthshow*> listGoods;
};

#endif // ORDER_H
