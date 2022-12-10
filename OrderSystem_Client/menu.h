#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QTableView>
#include <QObject>
#include <QStylePainter>
#include <QScrollArea>
#include <QScrollBar>
#include <QSqlError>
#include <QDebug>
#include "wigthshow.h"
namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_pushButton_shopping_clicked();


    void on_pushButton_ru_clicked();

    void getMag();

    void reviecedata(QString usernum);

    void on_listWidget_currentRowChanged(int currentRow);
private:
    Ui::Menu *ui;
    /*保存所有对象*/
    QList<wigthshow*> list_shop_all;
    QString usernum;
};

#endif // MENU_H
