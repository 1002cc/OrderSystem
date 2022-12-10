#include "signup.h"
#include "ui_signup.h"
#include "sql.h"
#include "land.h"

signup::signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
}

signup::~signup()
{
    delete ui;
}

void signup::on_pushButton_sig_clicked()
{
    /*获取账号密码和再次确认密码*/
    QString username = ui->lineEdit_id->text();
    QString password = ui->lineEdit_password_1->text();
    QString surepass = ui->lineEdit_password_2->text();
    /*判断是否为空*/
    if(username!=nullptr&&password!=nullptr&&surepass!=nullptr)
    {
        /*判断密码是否一致*/
        if(password == surepass)
        {
            QString sql=QString("insert into userdata(username,password) values('%1','%2');")
                    .arg(username).arg(password);
            /*创建执行语句对象*/
            QSqlQuery query;
            /*判断执行结果*/
            if(!query.exec(sql))
            {
                qDebug()<<"insert into error";
                QMessageBox::information(this,"注册认证","注册失败！");
            }
            else
            {
                qDebug()<<"insert into success";
                QMessageBox::information(this,"注册认证","注册成功！");
                land *w = new land;
                w->show();
                this->close();
            }

        }else{
            QMessageBox::information(this,"注册认证","两次密码输入不一致");
        }
    }else
    {
         QMessageBox::information(this,"注册认证","账号密码不能为空");
    }
}

void signup::on_pushButton_return_clicked()
{
    land *w = new land;
    w->show();
    this->close();
}
