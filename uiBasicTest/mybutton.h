#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QEvent>
#include <QIcon>


// 自定义控件————自定义按钮，用于学习qt事件相关内容。
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
    void enterEvent(QEvent *e);
    void leaveEvent(QEvent *e);

private:
    Ui::myButton *ui;
};

#endif // MYBUTTON_H
