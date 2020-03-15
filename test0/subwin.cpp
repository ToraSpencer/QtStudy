#include "subwin.h"


SubWin::SubWin(QWidget *parent) :
    QWidget(parent)
{

    this->setWindowTitle("次级窗口");


    b1.setParent(this);
    b1.setText("切换到主窗口");         // b1按钮按下，是发出请求切换窗口的信号，并不能直接实现窗口切换功能.
                                      // 只有主窗口对象才有权限操作主次两个窗口对象的show和hide

    b2.setParent(this);
    b2.setText("close");
    b2.setGeometry(0,150,150,30);
    
    
    // b1"切换到主窗口"按钮的信号-槽连接
    connect(&b1, &QPushButton::clicked, this, &SubWin::slot_send_signal);
    
    // b2关闭窗口按钮的信号——槽链接
    connect(&b2, &QPushButton::clicked, this, &SubWin::close);


    this->show();
}




SubWin::~SubWin()
{

}



void SubWin::slot_send_signal(void)
{
    emit signal_switch_window();

}
