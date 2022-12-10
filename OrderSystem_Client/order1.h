#ifndef ORDER_H
#define ORDER_H

#include <QWidget>
#include "wigthshow.h"
#include "menu.h"
#include "shoporder.h"
#include "dialogorder.h"

namespace Ui {
class order;
}

class order : public QWidget
{
    Q_OBJECT

public:
    explicit order(QList<wigthshow*> list_shop_alls,QString usernum="1",QWidget *parent = nullptr);
    ~order();

private slots:
    void on_pushButton_shopping_clicked();

    void on_pushButton_ru_clicked();

    void closeorder();
private:
    Ui::order *ui;
    int sum;
    QString username;
};

#endif // ORDER_H
