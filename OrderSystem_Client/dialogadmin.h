#ifndef DIALOGADMIN_H
#define DIALOGADMIN_H

#include <QDialog>


namespace Ui {
class Dialogadmin;
}

class Dialogadmin : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogadmin(QWidget *parent = nullptr);
    ~Dialogadmin();

private slots:
    void on_pushButton_cal_clicked();

    void on_pushButton_sure_clicked();

private:
    Ui::Dialogadmin *ui;
};

#endif // DIALOGADMIN_H
