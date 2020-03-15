#include "mylabel.h"
#include "ui_mylabel.h"


// 自定义控件————自定义标签，用于学习qt事件相关内容。
myLabel::myLabel(QWidget *parent) :
    QLabel(parent),
    ui(new Ui::myLabel)
{
    ui->setupUi(this);

    this->setMouseTracking(true);       // 设定追踪鼠标
}




myLabel::~myLabel()
{
    delete ui;
}


void myLabel::mousePressEvent(QMouseEvent *ev)
{
    QString msg;
    // 若触发事件的鼠标键是左键、右键、中键
    // Qt::MouseButton  QMouseEvent::button()
    if(ev->button() == Qt::LeftButton)      // LeftButton是MouseButton枚举常量中的一个
    {
        msg = QString("左键按下");
    }
    else if(ev->button() == Qt::RightButton)
    {
        msg = QString("右键按下");
    }
    else if(ev->button() == Qt::MidButton)
    {
        msg = QString("中键按下");
    }

    this->setText(msg);

}



void myLabel::mouseReleaseEvent(QMouseEvent *ev)
{


}



void myLabel::mouseMoveEvent(QMouseEvent *ev)
{
    int i = ev->x();            // 鼠标位置横坐标值
    int j = ev->y();
    QString coordinate = QString("鼠标位置(%1, %2)").arg(i).arg(j); // 格式化QT字符串。
    this->setText(coordinate);

}
