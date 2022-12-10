#include "land.h"
#include "sql.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QTime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int style_num =qrand()%5;
    /*设置样式*/
    QString filePath;
    if(style_num==0)
        filePath=":/qss/qss/style-1.qss";/*QSS文件所在的路径*/
    else if(style_num==1)
        filePath=":/qss/qss/style-2.qss";/*QSS文件所在的路径*/
    else if(style_num==2)
        filePath=":/qss/qss/style-3.qss";/*QSS文件所在的路径*/
    else if(style_num==3)
        filePath=":/qss/qss/style-4.qss";/*QSS文件所在的路径*/
    else
        filePath=":/qss/qss/style-5.qss";/*QSS文件所在的路径*/
    /*打开资源文件目录*/
    QFile file(filePath);
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    a.setStyleSheet(stylesheet);
    file.close();
    sql *sqlite=new sql;
    sqlite->create_table();
    land w;
    /*设置窗口标题*/
    w.setWindowTitle("Order System");
    /*设置程序图标 128x128 格式：ico*/
    w.setWindowIcon(QIcon(":/icon/image/icon/icon.ico"));
    /*设置窗口大小*/
    w.setFixedSize(w.width(),w.height());
    w.show();
    return a.exec();
}
