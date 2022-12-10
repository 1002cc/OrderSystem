#ifndef DIALOGORDER_H
#define DIALOGORDER_H

#include <QDialog>

namespace Ui {
class DialogOrder;
}

class DialogOrder : public QDialog
{
    Q_OBJECT

public:
    explicit DialogOrder(QWidget *parent = nullptr);
    ~DialogOrder();
    void setmoney(int money);
    void setusernum(QString usernum);
private slots:
    void on_pushButton_cal2_clicked();

    void on_pushButton_sure2_clicked();

private:
    Ui::DialogOrder *ui;
    QString usernum;
    int money;
};

#endif // DIALOGORDER_H
