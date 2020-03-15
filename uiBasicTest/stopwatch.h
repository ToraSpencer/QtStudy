#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QWidget>


// 自定义控件——秒表

namespace Ui {
class stopwatch;
}

class stopwatch : public QWidget
{
    Q_OBJECT

public:
    explicit stopwatch(QWidget *parent = 0);
    ~stopwatch();

private:
    Ui::stopwatch *ui;
};

#endif // STOPWATCH_H
