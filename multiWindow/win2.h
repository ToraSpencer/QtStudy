#ifndef WIN2_H
#define WIN2_H

#include <QWidget>
#include <QPixmap>

namespace Ui {
class win2;
}

class win2 : public QWidget
{
    Q_OBJECT

public:
    explicit win2(QWidget *parent = 0);
    ~win2();

private:
    Ui::win2 *ui;
};

#endif // WIN2_H
