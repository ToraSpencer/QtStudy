#include "selfintroduction.h"
#include "ui_selfintroduction.h"

selfIntroduction::selfIntroduction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::selfIntroduction)
{
    ui->setupUi(this);
}

selfIntroduction::~selfIntroduction()
{
    delete ui;
}
