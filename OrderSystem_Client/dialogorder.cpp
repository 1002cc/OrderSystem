#include "dialogorder.h"
#include "ui_dialogorder.h"

#include "menu.h"
DialogOrder::DialogOrder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogOrder)
{
    ui->setupUi(this);
    connect(ui->pushButton_sure2,SIGNAL(clicked(bool)),this,SLOT(closeorder()));
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    QString txet = "共计"+QString::number(money)+"元";
    ui->label_sum->setText(txet);
}

DialogOrder::~DialogOrder()
{
    delete ui;
}

void DialogOrder::setmoney(int money)
{
    this->money=money;
}

void DialogOrder::setusernum(QString usernum)
{
    this->usernum=usernum;
}

void DialogOrder::on_pushButton_cal2_clicked()
{
    this->close();
}

void DialogOrder::on_pushButton_sure2_clicked()
{
    Menu* m=new Menu();
    m->show();
    this->parentWidget()->close();
    this->close();
}
