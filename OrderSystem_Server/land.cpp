#include "land.h"
#include "ui_land.h"

land::land(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::land)
{
    ui->setupUi(this);
    /*设置输入密码回显*/
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);

    /*切换样式连接信号槽*/
    connect(ui->btn_s1,SIGNAL(clicked(bool)),this,SLOT(set_style()));
    connect(ui->btn_s2,SIGNAL(clicked(bool)),this,SLOT(set_style()));
    connect(ui->btn_s3,SIGNAL(clicked(bool)),this,SLOT(set_style()));
    connect(ui->btn_s4,SIGNAL(clicked(bool)),this,SLOT(set_style()));
    connect(ui->btn_s5,SIGNAL(clicked(bool)),this,SLOT(set_style()));
}

land::~land()
{
    delete ui;
}

/*
 * 登录功能
 * 普通账号登录---->用户设备登录--->展示选择商品--->支付
 * 账号密码保存到数据库中(账号唯一)，账号样式：桌号+5050 密码：123456
 * --------------------------------------------------
 * 管理员账号登录，自动判断---->跳转到管理页面---->修改商品信息
 *                                     ----->查看
 *                                     ----->增加商品 等
 * 管理员账号：admin 密码：1002
*/
void land::on_pushButton_login_clicked()
{
    /*获取账号和密码*/
    QString username = ui->lineEdit_id->text();
    QString password = ui->lineEdit_password->text();
    /*判断是否为空*/
    if(username==nullptr||password==nullptr)
    {
        QMessageBox::information(this,"登录认证","请输入正确的账号密码");
    }else
    {
        /*sqlite插入语句*/
        QString sql=QString("select * from admindata where name='%1' and password='%2'")
                .arg(username).arg(password);
        /*创建执行语句对象*/
        QSqlQuery query(sql);
        /*判断执行结果*/
        if(!query.next()){

            QMessageBox::information(this,"登录认证","登录失败,账户或者密码错误");
            qDebug()<< "error" <<query.lastError();
        }else{
            //QMessageBox::information(this,"登录认证","登录成功");
            /*登录成功后可以跳转到其他页面*/
            admin *s = new admin();
            s->show();
            this->close();
        }
    }
}

void land::set_style()
{
    /*获取发射信号的对象*/
    btn = qobject_cast<QPushButton*>(sender());
    QString filePath;

    if("btn_s1" == btn->objectName())       /*粉色样式*/
    {
        filePath = ":/qss/qss/style-1.qss";
    }else if("btn_s2" == btn->objectName())  /*黄蓝样式*/
    {
        filePath = ":/qss/qss/style-2.qss";
    }else if("btn_s3" == btn->objectName())  /*浅紫样式*/
    {
        filePath = ":/qss/qss/style-3.qss";
    }else if("btn_s4" == btn->objectName())  /*青绿样式*/
    {
        filePath = ":/qss/qss/style-4.qss";
    }else if("btn_s5" == btn->objectName())  /*青绿样式*/
    {
        filePath = ":/qss/qss/style-5.qss";
    }

    /*皮肤设置*/
    QFile file(filePath);
    /*QSS文件所在的路径*/
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    /*调用事件对象，全局设置样式*/
    qApp->setStyleSheet(stylesheet);
    /*关闭文件*/
    file.close();
}

/*跳转到注册页面*/
void land::on_pushButton_sign_clicked()
{
    signup* s= new signup;
    s->show();
    this->close();
}
