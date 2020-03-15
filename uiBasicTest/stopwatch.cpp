#include "stopwatch.h"
#include "ui_stopwatch.h"

stopwatch::stopwatch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::stopwatch)
{
    ui->setupUi(this);
}

stopwatch::~stopwatch()
{
    delete ui;
}
