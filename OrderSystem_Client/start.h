#ifndef START_H
#define START_H

#include <QWidget>

namespace Ui {
class start;
}

class start : public QWidget
{
    Q_OBJECT

public:
    explicit start(QWidget *parent = nullptr);
    ~start();
    void setusernum(QString usernum);

private slots:
    void on_pushButton_goto_menu_clicked();

    void on_pushButton_back_land_clicked();

    void closestart();
signals:
    void sendData_land(QString usernum);
private:
    Ui::start *ui;
    QString usernum;
};

#endif // START_H
