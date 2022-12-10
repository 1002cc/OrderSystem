#ifndef LAND_H
#define LAND_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QPushButton>
#include <QObject>
#include <QGraphicsDropShadowEffect>

#include "sql.h"
#include "admin.h"
#include "signup.h"
QT_BEGIN_NAMESPACE
namespace Ui { class land; }
QT_END_NAMESPACE

class land : public QMainWindow
{
    Q_OBJECT

public:
    land(QWidget *parent = nullptr);
    ~land();

public slots:
    void set_style();

private slots:
    void on_pushButton_login_clicked();
    void on_pushButton_sign_clicked();
signals:
    void sendData_land(QString s);

private:
    QPushButton* btn;
    Ui::land *ui;
    QString num_id;
};
#endif // LAND_H
