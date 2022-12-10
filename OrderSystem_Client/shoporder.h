#ifndef SHOPORDER_H
#define SHOPORDER_H

#include <QWidget>

namespace Ui {
class shoporder;
}

class shoporder : public QWidget
{
    Q_OBJECT

public:
    explicit shoporder(const QString &_filePath,const QString &name,const unsigned int count,QWidget *parent = nullptr);
    ~shoporder();

private:
    Ui::shoporder *ui;
};

#endif // SHOPORDER_H
