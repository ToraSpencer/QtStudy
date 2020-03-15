#include "mybutton.h"
#include "ui_mybutton.h"

myButton::myButton(QWidget *parent) :
    QPushButton(parent),
    ui(new Ui::myButton)
{
    ui->setupUi(this);

    this->setIcon(QIcon(":/imageSource/blue.png"));


}



myButton::~myButton()
{
    delete ui;
}




void myButton::enterEvent(QEvent *e)
{
    this->setIcon(QIcon(":/imageSource/bad.png"));
}



void myButton::leaveEvent(QEvent *e)
{
    this->setIcon(QIcon(":/imageSource/blue.png"));

}



void myButton::keyPressEvent(QKeyEvent* e)
{
    // int QKeyEvent::key() const——————返回按下的键对应的数字。
    qDebug()<< (char)(e->key());

    if(e->key() == Qt::Key_Shift)
    {
        this->setIcon(QIcon(":/imageSource/tiger.jpg"));
    }



}
