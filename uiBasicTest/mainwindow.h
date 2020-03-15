#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QPixmap>
#include <QMovie>
#include <QIcon>
#include <QSize>

#include <iostream>
#include <string>

#include "subwin.h"
#include "loginsystem.h"

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
    void on_bPrint_clicked();

    void on_bLogIn_clicked();

    void on_btn_changeFace_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
