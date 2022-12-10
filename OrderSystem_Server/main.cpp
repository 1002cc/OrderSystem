#include "land.h"
#include "sql.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*设置样式*/
    QFile file(":/qss/qss/style-1.qss");/*QSS文件所在的路径*/
    /*打开资源文件目录*/
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
