#include "mainwindow.h"
#include "ui_mainwindow.h"




// 多窗口程序

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 生成窗口2对象；
    this->pwin2 = new win2(nullptr);            // 注意窗口1和窗口2没有父子关系
    this->pwin2->hide();                        // 初始状态下窗口2不显示


    // 设置图片：
    ui->labelPic->setPixmap(QPixmap("C:\\cppCode\\QtCreatorTest\\uiBasicTest\\imageSource\\tiger.jpg"));


}



MainWindow::~MainWindow()
{
    delete ui;
}



// 窗口1的“去窗口2”按钮
void MainWindow::on_btn_1_2_clicked()
{
    // win2对象是私有数据，一开始就已经生成，直接使其显示
    this->pwin2->show();
    this->hide();
}



// 窗口1的“去窗口3”按钮
void MainWindow::on_btn_1_3_clicked()
{
    // win3对象不是私有数据，将其临时生成，然后显示：
    win3 *pwin3 = new win3(nullptr);
    pwin3->show();
    this->hide();
}
