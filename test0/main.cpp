#include <QApplication>     // 管理GUI应用程序的控制流、主要设置
#include <QDebug>

#include <string>
#include <iostream>


#include "MainWindow.h"
#include "SubWin.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
