#ifndef SUBWIN_H
#define SUBWIN_H

#include <QWidget>
#include <QMainWindow>          // 主窗口
#include <QPushButton>          // 按钮
#include <QMenuBar>             // 菜单栏
#include <QMenu>                // 菜单
#include <QAction>              // 菜单项（动作）
#include <QDialog>
#include <QDebug>


#include <iostream>
#include <string>





class SubWin : public QWidget
{
    Q_OBJECT
protected:
    QPushButton b1, b2;


signals:                                 // signals: qt扩展的关键字
    void signal_switch_window(void);
 

public:
    explicit SubWin(QWidget *parent = 0);
    ~SubWin();


    void slot_send_signal(void);          // 自定义槽函数——发送切换窗口信号； 注意subwin无法直接指挥主窗口切换窗口


private:

};

#endif // SUBWIN_H
