#include "mybutton.h"
#include "ui_mybutton.h"


// 自定义控件————自定义按钮，用于学习qt事件相关内容。
myButton::myButton(QWidget *parent) :
    QPushButton(parent),
    ui(new Ui::myButton)
{
    ui->setupUi(this);

    this->setIcon(QIcon("C:\\cppCode\\QtCreatorTest\\uiBasicTest\\imageSource\\blue.png"));

}



myButton::~myButton()
{
    delete ui;
}


void myButton::enterEvent(QEvent *e)
{
    this->setIcon(QIcon("C:\\cppCode\\QtCreatorTest\\uiBasicTest\\imageSource\\bad.png"));
}



void myButton::leaveEvent(QEvent *e)
{
    this->setIcon(QIcon("C:\\cppCode\\QtCreatorTest\\uiBasicTest\\imageSource\\blue.png"));

}
