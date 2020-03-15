#include "mycalculator.h"
#include "ui_mycalculator.h"



void model::setNum1(long n1)
{
    this->num1 = n1;
}



void model::setNum2(long n2)
{
    this->num2 = n2;
}



void model::setOp(char op)
{
    this->op = op;
}




long model::doExpr()
{
    //!!!考虑输入错误，以及输出为NaN的情形
    long result = 0;

    switch(this->op)
    {
    case 1:
        result = this->num1 + this->num2;
        break;
    case 2:
        result = this->num1 - this->num2;
        break;
    case 3:
        result = this->num1 * this->num2;
        break;
    case 4:
        result = this->num1 / this->num2;
        break;
    default:
        break;
    }

    return result;

}



// 在需要使用自定义控件的区域拖入空白控件，然后右键点击“提升为”，可以将其提升为本自定义控件。
myCalculator::myCalculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myCalculator)
{
    ui->setupUi(this);

    // 初始化
    pm = new model();
    numstr.clear();

    ui->le_display->setText("0");
}




// 数字键槽函数：
/*      按下数字键文本
 *
 */

myCalculator::~myCalculator()
{
    delete ui;
}



void myCalculator::on_btn_1_clicked()
{
    numstr+="1";
    ui->le_display->setText(numstr);
}



void myCalculator::on_btn_2_clicked()
{
    numstr+="2";
    ui->le_display->setText(numstr);
}



void myCalculator::on_btn_3_clicked()
{
    numstr+="3";
    ui->le_display->setText(numstr);
}



void myCalculator::on_btn_4_clicked()
{
    numstr+="4";
    ui->le_display->setText(numstr);
}



void myCalculator::on_btn_5_clicked()
{
    numstr+="5";
    ui->le_display->setText(numstr);
}



void myCalculator::on_btn_6_clicked()
{
    numstr+="6";
    ui->le_display->setText(numstr);
}



void myCalculator::on_btn_7_clicked()
{
    numstr+="7";
    ui->le_display->setText(numstr);
}



void myCalculator::on_btn_8_clicked()
{
    numstr+="8";
    ui->le_display->setText(numstr);
}



void myCalculator::on_btn_9_clicked()
{
    numstr+="9";
    ui->le_display->setText(numstr);
}


void myCalculator::on_btn_0_clicked()
{
    numstr+="0";
    ui->le_display->setText(numstr);
}



// 复位键：数据全部清空，显示“0”
void myCalculator::on_btn_clear_clicked()
{
    numstr.clear();

    ui->le_display->setText("0");
}



void myCalculator::on_btn_plus_clicked()
{
    long temp = (this->numstr).toLong();            // 当前文本条上的数字。

    // 数学模型中的参数赋值。
    pm->setNum1(temp);

    // 数学模型中的符号赋值。
    pm->setOp(1);

    // 重置要显示的数字字符串
    numstr.clear();

}



void myCalculator::on_btn_minus_clicked()
{
    long temp = (this->numstr).toLong();            // 当前文本条上的数字。

    // 数学模型中的参数赋值。
    pm->setNum1(temp);

    // 数学模型中的符号赋值。
    pm->setOp(2);

    // 重置要显示的数字字符串
    numstr.clear();

}



void myCalculator::on_btn_times_clicked()
{
    long temp = (this->numstr).toLong();            // 当前文本条上的数字。

    // 数学模型中的参数赋值。
    pm->setNum1(temp);

    // 数学模型中的符号赋值。
    pm->setOp(3);

    // 重置要显示的数字字符串
    numstr.clear();

}



void myCalculator::on_btn_divide_clicked()
{
    long temp = (this->numstr).toLong();            // 当前文本条上的数字。

    // 数学模型中的参数赋值。
    pm->setNum1(temp);

    // 数学模型中的符号赋值。
    pm->setOp(4);

    // 重置要显示的数字字符串
    numstr.clear();

}



void myCalculator::on_btn_equal_clicked()
{
    long temp = (this->numstr).toLong();            // 当前文本条上的数字。

    // 数学模型中的参数赋值。
    pm->setNum2(temp);

    // 计算结果；
    this->result = pm->doExpr();

    // 显示结果：
    numstr = QString::number(this->result);         // QString::number()数字转换为字符串
    ui->le_display->setText(numstr);
}




