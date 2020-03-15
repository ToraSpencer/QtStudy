#ifndef SELFINTRODUCTION_H
#define SELFINTRODUCTION_H

#include <QWidget>

namespace Ui {
class selfIntroduction;
}

class selfIntroduction : public QWidget
{
    Q_OBJECT

public:
    explicit selfIntroduction(QWidget *parent = 0);
    ~selfIntroduction();

private:
    Ui::selfIntroduction *ui;
};

#endif // SELFINTRODUCTION_H
