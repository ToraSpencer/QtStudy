#include "myslider.h"
#include "ui_myslider.h"

mySlider::mySlider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mySlider)
{
    ui->setupUi(this);

    psb1 = new QSpinBox(this);
    psl1 = new QSlider(Qt::Horizontal, this);  // 不指定方向的话，默认滑动条方向是垂直的

    // 控件放入水平布局器中：
    QVBoxLayout *pvl = new QVBoxLayout();
    setLayout(pvl);

    // 设置滑动条psl1属性：
    psl1->setMinimum(0);                 // 滑动条最小值
    psl1->setMaximum(100);
    psl1->setValue(10);                  // 滑动条初始值


    // 滑动条psl1的connect函数——————改变滑动条，来给下拉框设值
    /*
     * 滑动条信号：   void  QAbstractSlider::valueChanged(int)
     * 下拉框槽：    void setValue(int val)
     */
    connect(psl1, &QSlider::valueChanged, psb1, &QSpinBox::setValue);


    // 下拉框psb1的connect函数————改变下拉框中的数字，来设定滑动条的位置
    /*
     * 下拉框信号： void ~::valueChanged(int)——————有重载，貌似默认不是这个，所以需要用static_cast改变成和槽一样的函数指针类型。
     *  滑动条槽：void ~::setValue(int)
     */
    connect(psb1, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), psl1, &QSlider::setValue);



}

mySlider::~mySlider()
{
    delete ui;
}
