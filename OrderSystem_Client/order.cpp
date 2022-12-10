#include "order.h"
#include "ui_order.h"
#include "menu.h"
#include "shoporder.h"
#include "dialogorder.h"
#include <QDebug>
#include <QObject>

Order::Order(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Order)
{
    ui->setupUi(this);
}

Order::~Order()
{
    delete ui;
}

void Order::on_pushButton_shopping_clicked()
{
   DialogOrder* d=new DialogOrder(this);
   d->setmoney(sum);
   d->setusernum(usernum);
   d->show();
}

void Order::on_pushButton_ru_clicked()
{
    this->parentWidget()->show();
    this->close();
}

void Order::setusernum(QString usernum)
{
    this->usernum=usernum;
    ui->label_number->setText(usernum);
}

void Order::setlistshop(QList<wigthshow *> list_goods)
{
    this->listGoods=list_goods;
    //设置显示框
    ui->scrollArea->setWidgetResizable(true);
    ui->scrollArea->setWidget(ui->show_order_area);
    QVBoxLayout* pSubLayout = new QVBoxLayout(this);
    ui->show_order_area->setLayout(pSubLayout);
    sum=0;
    QList<tcpsenddata> tcpdata;
    tcpsenddata tcpt;
    for(int i=0;i<listGoods.size();i++)
    {
        if(listGoods[i]->getcount())
        {
           pSubLayout->addWidget(new shoporder(listGoods[i]->get_filePath(),listGoods[i]->get_flil_name(),listGoods[i]->getcount()));
           sum+=listGoods[i]->get_money();
           tcpt.name=listGoods[i]->get_flil_name();
           tcpt.count=listGoods[i]->getcount();
           tcpt.money=listGoods[i]->get_money();
           tcpdata.append(tcpt);
        }
    }
    QString txet = "共计"+QString::number(sum)+"元";
    ui->label_money->setText(txet);
}

void Order::closeorder()
{
    this->close();
}
