#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QEvent>
#include <QKeyEvent>
#include <QIcon>
#include <QDebug>


namespace Ui {
class myButton;
}



class myButton : public QPushButton
{
    Q_OBJECT

public:
    explicit myButton(QWidget *parent = 0);
    ~myButton();

protected:
    void enterEvent(QEvent *e);                 // 重写鼠标进入事件
    void leaveEvent(QEvent *e);
    void keyPressEvent(QKeyEvent *e);           // 重写键盘事件

private:
    Ui::myButton *ui;
};

#endif // MYBUTTON_H
