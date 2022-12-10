#include "sql.h"

sql::sql()
{
    /*创建sqlite数据库*/
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/gec/Order_System_Project/Db/userdata.db");
    /*创建执行语句对象*/
    query =new QSqlQuery(db);
    if(!db.open())
    {
        qDebug()<<"open error";
        error = db.lastError();
    }
}


sql::~sql()
{
    delete query;
}

void sql::create_table()
{
    /*创建sqlite数据库表*/
    QString createsql=QString("create table if not exists userdata(id integer primary key autoincrement,"
                        "username ntext unique not NULL,"
                        "password ntext not NULL)");
    QSqlQuery query(db);
    if(!query.exec(createsql)){
        qDebug()<<"table create error";
    }
    else{
        qDebug()<<"table create success";
    }
    QString createsql1=QString("create table if not exists menudata(ID INTEGER PRIMARY KEY autoincrement,"
                        "名称 ntext text not NULL,"
                        "图片路径   text not NULL,"
                        "价格      text not NULL,"
                        "库存      text not NULL,"
                        "分类   text not NULL,"
                        "备注      text not NULL)");
    if(!query.exec(createsql1)){
        qDebug()<< "error" <<query.lastError();
    }
    else{
        qDebug()<<"menudata table create success";
    }
}

int sql::db_query(QString m_query_sql)
{
    query->prepare(m_query_sql);
    return query->exec();
}

void sql::add_data(const QString &name, const QString &_filepath, const unsigned int &money, const unsigned int &count, const QString &classi, const QString &word)
{
    QString sql=QString("INSERT INTO menudata(名称,图片路径,价格,库存,分类,备注) VALUES('%1','%2','%3','%4','%5','%6');")
            .arg(name).arg(_filepath).arg(money).arg(count).arg(classi).arg(word);
    /*判断执行结果*/
    if(!query->exec(sql))
    {
        qDebug()<< "error" <<query->lastError();
    }
}

QString sql::getError()
{
     return error.text();
}
