#include "wigthshow.h"
#include "ui_wigthshow.h"

wigthshow::wigthshow(const QString &_filePath,const QString &name,const QString &money,QWidget *parent):
    QWidget(parent),
    ui(new Ui::wigthshow)
{
    ui->setupUi(this);
    this->count=0;
    this->_filePath=_filePath;
    this->flil_name=name;
    this->money=money.toInt();
    ui->label_showimage->setPixmap(QPixmap(_filePath));
    ui->label_showimage->setScaledContents(true);
    ui->label_count->setText(QString::number(count));
    ui->label_name->setText(name);
    QString txet = money+"元";
    ui->label_money1->setText(txet);
}

wigthshow::~wigthshow()
{
    delete ui;
}

unsigned int wigthshow::getcount()
{
    return count;
}

QString wigthshow::get_filePath()
{
    return _filePath;
}

QString wigthshow::get_flil_name()
{
    return flil_name;
}

int wigthshow::get_money()
{
    return money;
}

void wigthshow::on_pushButton_jian_clicked()
{
    count--;
    if(count<=0)
        count=0;
    ui->label_count->setText(QString::number(count));
}

void wigthshow::on_pushButton_jia_clicked()
{
    count++;
    ui->label_count->setText(QString::number(count));
}
