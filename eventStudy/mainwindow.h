#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include <QIcon>
#include <QPixmap>
#include <QTimerEvent>          // 定时器事件
#include <QCloseEvent>          // 关闭窗口事件
#include <QMessageBox>          // 标准对话框类



namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


protected:
    void closeEvent(QCloseEvent *e);            // 重写关闭窗口事件

    bool eventFilter(QObject *po, QEvent *e);   // 事件过滤器





private:
    Ui::MainWindow *ui;



};

#endif // MAINWINDOW_H
