#include "loginsystem.h"
#include "ui_loginsystem.h"

logInSystem::logInSystem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::logInSystem)
{
    ui->setupUi(this);
    ui->labelHead->setPixmap(QPixmap("C:\\cppCode\\QtCreatorTest\\uiBasicTest\\imageSource\\who.png"));


}

logInSystem::~logInSystem()
{
    delete ui;
}
