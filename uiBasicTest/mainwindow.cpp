#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // 设计器设计窗口时，创建的控件都是ui的成员数据，可以通过ui来对其进行读写。
    ui->LabelPrint->setText("请输入文字");

    // QLable中添加要展示的内容：
    //      QLable中添加图片。
    ui->LabelPic->setPixmap(QPixmap("C:\\cppCo"         // QLabel::setPixmap()————设定QLabel类的成员数据pixmap
                                    "de\\QtCreatorTest\\uiBasicTest\\imageSource\\tiger.jpg"));  // 目前没找到用相对路径的方法。

    ui->LabelPic->setPixmap(QPixmap("C:\\cppCode\\QtCreatorTest\\uiBasicTest\\imageSource\\who.jpg"));      //???为什么不显示？
    ui->LabelPic->setPixmap(QPixmap("://imageSource/bad.png"));


    //      QLable中添加动图
    QMovie *pm1 = new QMovie("C:\\cppCode\\QtCreatorTest\\uiBasicTest\\imageSource\\pushin.gif");
    ui->LabelGif->setMovie(pm1);                    // QLabel::setMovie()————设定QLabel类的成员数据movie
    pm1->start();                                   // QMovie::start()————动画启动


    // 设置按钮的图片
    ui->btn_changeFace->setIcon(QIcon("C:\\cppCode\\QtCreatorTest\\uiBasicTest\\imageSource\\blue.png"));
    ui->btn_changeFace->setIconSize(QSize(100,100));
}

MainWindow::~MainWindow()
{
    delete ui;
}



// 在设计器界面右击QPushButton，点击“转到槽”，会生成此槽函数，此槽函数不需要connect就可以直接用。
// “控制台打印文字”按钮槽函数
void MainWindow::on_bPrint_clicked()
{
    // 获取QLineEdit中输入的文字，在控制台打印。
    QString str1 = ui->lineEdit1->text();           // QLineEdit::text()————返回文本编辑框中的字符串（QString）。
    qDebug() << str1;
}



// “用户名密码登录系统”按钮槽函数
void MainWindow::on_bLogIn_clicked()
{
    logInSystem *plog = new logInSystem(nullptr);
    plog->show();

}



void MainWindow::on_btn_changeFace_clicked()
{

}
