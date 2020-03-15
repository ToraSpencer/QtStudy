#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>

#include "win2.h"
#include "win3.h"




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_1_2_clicked();

    void on_btn_1_3_clicked();

private:
    Ui::MainWindow *ui;
    win2 *pwin2;                // 窗口2对象的指针。

};

#endif // MAINWINDOW_H
