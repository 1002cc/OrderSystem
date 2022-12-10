#include "dialogadmin.h"
#include "ui_dialogadmin.h"
#include "sql.h"
#include "land.h"

Dialogadmin::Dialogadmin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogadmin)
{
    ui->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    /*绑定信号槽，当确认按键按下后关闭start页面*/
    connect(ui->pushButton_sure,SIGNAL(clicked(bool)),this,SLOT(closestart()));
}

Dialogadmin::~Dialogadmin()
{
    delete ui;
}

void Dialogadmin::on_pushButton_cal_clicked()
{
    this->close();
}

void Dialogadmin::on_pushButton_sure_clicked()
{
    /*获取账号和密码*/
    QString username = ui->lineEdit_admin_id->text();
    QString password = ui->lineEdit_admin_password->text();
    /*判断是否为空*/
    if(username==nullptr||password==nullptr)
    {
        QMessageBox::information(this,"登录认证","请输入正确的账号密码");
    }else
    {
        /*sqlite插入语句*/
        QString sql=QString("select * from admindata where name='%1' and password='%2'")
                .arg(username).arg(password);
        qDebug() << sql;
        /*创建执行语句对象*/
        QSqlQuery query(sql);
        /*判断执行结果*/
        if(!query.next())
        {
            qDebug() << query.lastError();
            QMessageBox::information(this,"登录认证","登录失败,账户或者密码错误");
        }
        else
        {
            /*返回登录界面*/
            land *m = new land();
            m->show();
            this->close();
        }
    }
}
