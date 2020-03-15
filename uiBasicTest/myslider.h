#ifndef MYSLIDER_H
#define MYSLIDER_H

#include <QWidget>
#include <QSlider>
#include <QSpinBox>
#include <QString>
#include <QEvent>
#include <QHBoxLayout>          // 水平布局器
#include <QVBoxLayout>

// 自定义滑动条控件
namespace Ui {
class mySlider;
}



class mySlider : public QWidget
{
    Q_OBJECT

public:
    explicit mySlider(QWidget *parent = 0);
    ~mySlider();

private:
    Ui::mySlider *ui;
    QSpinBox *psb1;
    QSlider *psl1;
};

#endif // MYSLIDER_H
