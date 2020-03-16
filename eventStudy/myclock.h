#ifndef MYCLOCK_H
#define MYCLOCK_H

#include <QWidget>
#include <QTimer>               // 定时器
#include <QString>
#include <QTime>






namespace Ui {
class myClock;
}



class myClock : public QWidget
{
    Q_OBJECT

public:
    explicit myClock(QWidget *parent = 0);
    ~myClock();

public slots:
    void on_timer_timeout();            // 定时器timeout信号的槽函数


private slots:
    void on_btn_show_clicked();

private:
    Ui::myClock *ui;
    QTimer *timer1;
};

#endif // MYCLOCK_H
