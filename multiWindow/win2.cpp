#include "win2.h"
#include "ui_win2.h"

win2::win2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::win2)
{
    ui->setupUi(this);


    ui->labelPic->setPixmap(QPixmap("C:\\cppCode\\QtCreatorTest\\multiWindow\\little tiger"));
}



win2::~win2()
{
    delete ui;
}
