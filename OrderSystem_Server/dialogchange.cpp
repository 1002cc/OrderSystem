#include "dialogchange.h"
#include "ui_dialogchange.h"

Dialogchange::Dialogchange(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogchange)
{
    ui->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
}

Dialogchange::~Dialogchange()
{
    delete ui;
}
void Dialogchange::on_pushButton_add_clicked()
{
    QString name  =ui->textEdit_name->toPlainText();
    QString path  =ui->textEdit_path->toPlainText();
    QString money =ui->textEdit_money->toPlainText();
    QString count =ui->textEdit_conut->toPlainText();
    QString claasi=ui->textEdit_claasi->toPlainText();
    QString notes =ui->textEdit_notes->toPlainText();

    QString sql =QString("INSERT INTO menudata(名称,图片路径,价格,库存,分类,备注) VALUES('%1','%2','%3','%4','%5','%6');")
            .arg(name).arg(path).arg(money).arg(count).arg(claasi).arg(notes);
    qDebug() << sql;
    query->exec(sql);
    querydel->setQuery("select * from menudata");
}

void Dialogchange::on_pushButton_ret_clicked()
{
   this->close();
}
