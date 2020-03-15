#ifndef LOGINSYSTEM_H
#define LOGINSYSTEM_H

#include <QWidget>
#include <QPixmap>


namespace Ui {
class logInSystem;
}

class logInSystem : public QWidget
{
    Q_OBJECT

public:
    explicit logInSystem(QWidget *parent = 0);
    ~logInSystem();

private:
    Ui::logInSystem *ui;
};

#endif // LOGINSYSTEM_H
