#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QString>
#include <QEvent>
#include <QMouseEvent>



// 自定义控件————自定义标签，用于学习qt事件相关内容。
namespace Ui {
class myLabel;
}



class myLabel : public QLabel
{
    Q_OBJECT

public:
    explicit myLabel(QWidget *parent = 0);
    ~myLabel();

protected:
    void mousePressEvent(QMouseEvent *ev);             // 重写鼠标按住事件函数，继承自QWidget，是虚函数
    void mouseReleaseEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);


private:
    Ui::myLabel *ui;
};



#endif // MYLABEL_H
