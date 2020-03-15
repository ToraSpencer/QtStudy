#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>          // 主窗口
#include <QPushButton>          // 按钮
#include <QMenuBar>             // 菜单栏
#include <QMenu>                // 菜单
#include <QAction>              // 菜单项（动作）
#include <QDialog>
#include <QDebug>
#include <QToolBar>             // 工具栏
#include <QStatusBar>           // 状态栏
#include <QLabel>               // 标签
#include <QTextEdit>            // 文本编辑框
#include <QDockWidget>          // 浮动窗口
#include <QMessageBox>          // 标准对话框
#include <QFileDialog>          // 文件对话框
#include <QLineEdit>
#include <QSlider>

#include <iostream>
#include <string>

#include "SubWin.h"



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



public slots:              // slots关键字，在此之后声明的槽函数都被包含在SLOT()之中————目前有BUG以后再说
    void switchWindow(void);                    // 切换窗口操作：隐藏本窗口，显示子窗口。
    void deal_signal_switch_window(void);       // 槽函数——处理次级窗口对象发出的切换窗口signal

private:
    QPushButton b1;
    QPushButton *pb1, *pb2, *pb3;
    SubWin *psw;               // 子窗口对象，初始状态为隐藏。
    QSlider *psl1;
    QLineEdit *ple1;



};
#endif // MAINWINDOW_H
