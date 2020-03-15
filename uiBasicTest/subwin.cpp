#include "subwin.h"
#include "ui_subwin.h"

subwin::subwin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::subwin)
{

    ui->setupUi(this);
    this->setWindowTitle("子窗口");



}

subwin::~subwin()
{
    delete ui;
}
