#include "myclock.h"
#include "ui_myclock.h"



myClock::myClock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myClock)
{
    ui->setupUi(this);


    // int QObject::startTimer(int interval, Qt::TimerType timerType = Qt::CoarseTimer)
    this->timer1 = this->startTimer(1000);             // 启动定时器，设定定时器事件的时间间隔为1000ms
    this->timer2 = this->startTimer(500);

}



myClock::~myClock()
{
    delete ui;
}


void myClock::timerEvent(QTimerEvent *e)
{
    static long now1 = 0;
    static long now2 = 0;
    if(e->timerId() == timer1)
    {
        QString str = QString("now time is: %1").arg(now1++);        // 定时器事件每发生一次，now+1
        ui->label1->setText(str);
    }
    else
    {
        QString str = QString("now time is: %1").arg(now2++);        // 定时器事件每发生一次，now+1
        ui->label2->setText(str);
    }

}
