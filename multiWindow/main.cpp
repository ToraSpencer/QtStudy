#include "mainwindow.h"
#include <QApplication>

// 管理多窗口：
/*      方法一：将其他窗口对象设置为主窗口的私有数据，但没有父子关系，是独立的。
 *
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
