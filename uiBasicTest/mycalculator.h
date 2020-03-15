#ifndef MYCALCULATOR_H
#define MYCALCULATOR_H

#include <QWidget>
#include <QString>


// 计算机功能实现的基本思想：
/*      显示时处理的是QString，计算时处理的是long
 *
 *
 */
namespace Ui {
class myCalculator;
}


// 两数计算的数学模型
class model
{
private:
    long  num1, num2;
    char op;                // 1,2,3,4分别表示加减乘除运算符

public:
    model() = default;
    void setNum1(long n1);
    void setNum2(long n2);
    void setOp(char op);
    long doExpr();          // 计算算式，返回结果
};



class myCalculator : public QWidget
{
    Q_OBJECT

public:
    explicit myCalculator(QWidget *parent = 0);
    ~myCalculator();

private:
    Ui::myCalculator *ui;
    model *pm;
    QString numstr;             // 文本条上显示的数字
    long result;                // 数学模型返回的结果。


private slots:
    void on_btn_1_clicked();

    void on_btn_2_clicked();

    void on_btn_3_clicked();

    void on_btn_4_clicked();

    void on_btn_5_clicked();

    void on_btn_6_clicked();

    void on_btn_7_clicked();

    void on_btn_8_clicked();

    void on_btn_9_clicked();

    void on_btn_plus_clicked();

    void on_btn_minus_clicked();

    void on_btn_times_clicked();

    void on_btn_divide_clicked();

    void on_btn_equal_clicked();

    void on_btn_clear_clicked();

    void on_btn_0_clicked();


};

#endif // MYCALCULATOR_H
