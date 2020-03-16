#include "myclock.h"
#include "ui_myclock.h"


// lcd时钟，使用QTimer来刷新时间数据。
myClock::myClock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myClock)
{
    ui->setupUi(this);

    // 创建定时器对象，设置属性
    timer1 = new QTimer(this);
    timer1->stop();
    timer1->setInterval(1000);       // 设置定时器中断周期interval为1000ms，即每隔1s发出一次timeout信号

    // 定时器timer1的timeout信号的连接函数
    connect(timer1, &QTimer::timeout, this, &myClock::on_timer_timeout);

}



myClock::~myClock()
{
    delete ui;
}




// 定时器timeout信号的槽函数
void myClock::on_timer_timeout()
{
    QTime *now = new QTime();
    *now = QTime::currentTime();
    ui->lcd_hour->display(now->hour());
    ui->lcd_min->display(now->minute());
    ui->lcd_sec->display(now->second());
    delete now;
}



// show time按钮的槽函数
void myClock::on_btn_show_clicked()
{
    this->timer1->start();
}
