#ifndef WIN3_H
#define WIN3_H

#include <QWidget>
#include <QPixmap>

#include "mainwindow.h"


namespace Ui {
class win3;
}

class win3 : public QWidget
{
    Q_OBJECT

public:
    explicit win3(QWidget *parent = 0);
    ~win3();



private slots:
    void on_btn_3_1_clicked();

private:
    Ui::win3 *ui;
};

#endif // WIN3_H
