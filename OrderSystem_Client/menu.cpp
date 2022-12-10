#include "menu.h"
#include "ui_menu.h"

#include "land.h"
#include "order.h"
#include "sql.h"
#include "start.h"
Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground);

    ui->scrollArea->setWidgetResizable(true);
    ui->scrollArea->setWidget(ui->scrollAreaWidgetContents_3);
    QHBoxLayout* pSubLayout = new QHBoxLayout();
    ui->scrollAreaWidgetContents_3->setLayout(pSubLayout);

    ui->scrollArea_2->setWidgetResizable(true);
    ui->scrollArea_2->setWidget(ui->scrollAreaWidgetContents_4);
    QHBoxLayout* pSubLayout2 = new QHBoxLayout(ui->scrollAreaWidgetContents_4);
    ui->scrollAreaWidgetContents_3->setLayout(pSubLayout2);
 ui->label_number->setText(this->usernum);
    ui->scrollArea_3->setWidgetResizable(true);
    ui->scrollArea_3->setWidget(ui->scrollAreaWidgetContents_5);
    QHBoxLayout* pSubLayout3 = new QHBoxLayout(ui->scrollAreaWidgetContents_5);
    ui->scrollAreaWidgetContents_3->setLayout(pSubLayout3);

    QString sqlstr = "select * from menudata";
    QSqlQuery query(sqlstr);
    query.first();
    do
    {
        wigthshow *mo=new wigthshow(query.value(2).toString(),query.value(1).toString(),query.value(3).toString());
        if(query.value(5).toString()=="茶点")
        {
             pSubLayout->addWidget(mo);;
        }
        if(query.value(5).toString()=="小炒")
        {
             pSubLayout2->addWidget(mo);
        }
        if(query.value(5).toString()=="饮料")
        {
             pSubLayout3->addWidget(mo);
        }
        list_shop_all.append(mo);
    }while(query.next());

}

Menu::~Menu()
{
    delete ui;
}

/*打开下单页面*/
void Menu::on_pushButton_shopping_clicked()
{
    Order*o=new Order(this);
    o->setlistshop(list_shop_all);
    o->setusernum(usernum);
    o->show();
    this->hide();
}

void Menu::getMag()
{
    this->show();
}

void Menu::reviecedata(QString usernum)
{
    this->usernum=usernum;
    ui->label_number->setText(this->usernum);
}

void Menu::on_pushButton_ru_clicked()
{
    start* s=new start();
    s->setusernum(usernum);
    s->show();
    this->close();
}


void Menu::on_listWidget_currentRowChanged(int currentRow)
{
    ui->tabWidget->setCurrentIndex(currentRow);
}
