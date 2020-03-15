#ifndef MYCLOCK_H
#define MYCLOCK_H

#include <QWidget>
#include <QTimer>               // 定时器
#include <QString>



namespace Ui {
class myClock;
}



class myClock : public QWidget
{
    Q_OBJECT

public:
    explicit myClock(QWidget *parent = 0);
    ~myClock();

protected:
    void timerEvent(QTimerEvent *);

private:
    Ui::myClock *ui;
    int timer1, timer2;
};

#endif // MYCLOCK_H
