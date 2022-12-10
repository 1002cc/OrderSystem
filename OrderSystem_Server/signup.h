#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include <QMainWindow>
namespace Ui {
class signup;
}

class signup : public QWidget
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:

    void on_pushButton_sig_clicked();

    void on_pushButton_return_clicked();

private:
    Ui::signup *ui;
};

#endif // SIGNUP_H
