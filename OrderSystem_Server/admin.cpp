#include "admin.h"
#include "ui_admin.h"
#include "dialogchange.h"

admin::admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
    //数据库显示
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","rconntosqlite");
    db.setDatabaseName("/home/gec/Order_System_Project/Db/userdata.db");
    if(!db.open())
    {
        qDebug()<<"open error";
    }
    query = new QSqlQuery(db);
    querydel = new QSqlQueryModel();
    querydel->setQuery("select * from menudata");
    ui->tableView_sql->setModel(querydel);
    querydel->setHeaderData(0,Qt::Horizontal,"序号");
    querydel->setHeaderData(1,Qt::Horizontal,"名称");
    querydel->setHeaderData(2,Qt::Horizontal,"图片路径");
    querydel->setHeaderData(3,Qt::Horizontal,"价格");
    querydel->setHeaderData(4,Qt::Horizontal,"库存");
    querydel->setHeaderData(5,Qt::Horizontal,"分类");
    querydel->setHeaderData(6,Qt::Horizontal,"备注");
    this->ui->tableView_sql->verticalHeader()->hide();
    this->ui->tableView_sql->setColumnWidth(0,20);
    this->ui->tableView_sql->setColumnWidth(1,80);
    this->ui->tableView_sql->setColumnWidth(2,200);
    this->ui->tableView_sql->setColumnWidth(3,50);
    this->ui->tableView_sql->setColumnWidth(4,50);
    this->ui->tableView_sql->setColumnWidth(5,50);
    this->ui->tableView_sql->setColumnWidth(6,100);

    //server_s = new server(8888);
    //connect(server_s,SIGNAL(giveMsg),this,SLOT(adminGiveMsg(QAtring)));
}

admin::~admin()
{
    delete ui;
    delete server_s;
}

void admin::on_listWidget_currentRowChanged(int currentRow)
{
     ui->tabWidget->setCurrentIndex(currentRow);
}

void admin::on_pushButton_ru_clicked()
{
    land*l=new land();
    l->show();
    this->close();
}
/*信号槽收到信息处理*/
void admin::adminGiveMsg(QString)
{

}

void admin::on_tableView_sql_clicked(const QModelIndex &index)
{
    /*获取tableview单击的内容，并显示到文本中*/
    QString text =index.sibling(index.row(),index.column()).data().toString();
    this->ui->label_show->setText(text);
    this->indexdel=index;
}

void admin::on_pushButton_add_clicked()
{
    Dialogchange* d=new Dialogchange(this);
    d->show();
}

void admin::on_pushButton_chang_clicked()
{
    QString textc = ui->textEdit_updata->toPlainText();
    QString nametitle = this->ui->tableView_sql->model()->headerData(indexdel.column(), Qt::Horizontal).toString();
    QString ID=indexdel.sibling(indexdel.row(),0).data().toString();
    QString sql ="UPDATE menudata set "+nametitle+"="+textc+" where "+"ID ="+ID;
    qDebug()<<sql;
    query->exec(sql);
    querydel->setQuery("select * from menudata");
    //执行完清空文本框
    ui->textEdit_updata->setText(" ");
}

void admin::on_pushButton_delete_clicked()
{
    QString textd=indexdel.sibling(indexdel.row(),0).data().toString();
    QString sql ="delete from menudata where id="+textd;
    query->exec(sql);
    querydel->setQuery("select * from menudata");
}
