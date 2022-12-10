#include "start.h"
#include "ui_start.h"
#include "dialogadmin.h"
#include "menu.h"

start::start(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::start)
{
    ui->setupUi(this);
}

start::~start()
{
    delete ui;
}

void start::setusernum(QString usernum)
{
    this->usernum=usernum;
}

void start::on_pushButton_goto_menu_clicked()
{

    Menu*m=new Menu();
    connect(this,SIGNAL(sendData_land(QString)),m,SLOT(reviecedata(QString)));
    emit sendData_land(usernum);
    m->show();
    this->close();
}

void start::on_pushButton_back_land_clicked()
{
    Dialogadmin*d=new Dialogadmin();
    d->show();

}

void start::closestart()
{
    this->close();
}
