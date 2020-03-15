#include "win3.h"
#include "ui_win3.h"



win3::win3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::win3)
{
    ui->setupUi(this);

    ui->labelPic->setPixmap(QPixmap("C:\\cppCode\\QtCreatorTest\\multiWindow\\bad.png"));
}



win3::~win3()
{
    delete ui;
}


// 窗口3的“去窗口1”函数
void win3::on_btn_3_1_clicked()
{

}
