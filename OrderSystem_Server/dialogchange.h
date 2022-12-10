#ifndef DIALOGCHANGE_H
#define DIALOGCHANGE_H

#include <QDialog>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class Dialogchange;
}

class Dialogchange : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogchange(QWidget *parent = nullptr);
    ~Dialogchange();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_ret_clicked();
private:
    Ui::Dialogchange *ui;
    QSqlQuery* query;
    QSqlQueryModel* querydel;
};

#endif // DIALOGCHANGE_H
