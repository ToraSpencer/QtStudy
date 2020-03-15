#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label1->installEventFilter(this);       // 该空间使用事件过滤器
    ui->label2->installEventFilter(this);

}



MainWindow::~MainWindow()
{
    delete ui;
}



// 重写关闭窗口事件——————弹出对话框来确认
void MainWindow::closeEvent(QCloseEvent *e)
{
    int ret = QMessageBox::question(this, "确认退出窗口", "确认要退出系统吗？");
    if(ret == QMessageBox::Yes)
    {
        e->accept();
    }
    else
    {
        e->ignore();
    }


}



// 使用事件过滤器，在控件上一级定义事件响应，这样就不需要自定义控件了。
bool MainWindow::eventFilter(QObject *po, QEvent *e)
{
    if(po == ui->label1)
    {
        if(e->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *em = static_cast<QMouseEvent *>(e);
            ui->label1->setText(QString("鼠标坐标：%1, %2").arg(em->x()).arg(em->y()));
        }
        else if(e->type() == QEvent::MouseButtonRelease)
        {
            ui->label1->setStyleSheet("background-image:url(:/imageSource/tiger.jpg)");

        }
        else
        {
            return QWidget::eventFilter(po, e);
        }
    }
    else if(po == ui->label2)
    {
        if(e->type() == QEvent::MouseButtonPress)
        {
            ui->label2->setStyleSheet("background-color: rgb(255,0,0)");
        }
        else if(e->type() == QEvent::MouseButtonRelease)
        {
            ui->label2->setStyleSheet("background-color: blue");
        }
        else
        {
            return QWidget::eventFilter(po, e);
        }

    }
    else
    {
        return QWidget::eventFilter(po, e);

    }

}
