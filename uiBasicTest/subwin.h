#ifndef SUBWIN_H
#define SUBWIN_H

#include <QWidget>

namespace Ui {
class subwin;
}

class subwin : public QWidget
{
    Q_OBJECT

public:
    explicit subwin(QWidget *parent = 0);
    ~subwin();

private:
    Ui::subwin *ui;
};

#endif // SUBWIN_H
