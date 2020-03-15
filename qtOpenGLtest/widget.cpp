#include "widget.h"
#include "ui_widget.h"



/*
 * 从父类QGLWidget中继承三个虚函数，分别用于初始化、绘制和窗口刷新的时候的重置函数
 *      void initializeGL();
 *      void resizeGL(int w, int h);
 *      void paintGL();
*/


Widget::Widget(QWidget *parent) :
    QGLWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}




Widget::~Widget()
{
    delete ui;
}


// 初始化OpenGL;
void Widget::initializeGL()
{
    //设置widget的坐标和尺寸
    setGeometry(300, 150, 500, 500);
    //设置清除时颜色
    glClearColor(0.0, 0.0, 0.0, 0);
}



void Widget::resizeGL(int w, int h)
{
    //视口变换
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    //投影变换
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0,(GLdouble)w/(GLdouble)h,0.1,10000.0);
    //视图变换
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0,0.0,15.0,0.0,0.0,0.0,0.0,1.0,0.0);
}



void Widget::paintGL()
{
    //清屏
    glClear(GL_COLOR_BUFFER_BIT);
    //绘制七彩三角形
    glBegin(GL_TRIANGLES);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-2,0,0);
    glColor3f(0.0,1.0,0.0);
    glVertex3f(2,0,0);
    glColor3f(0.0,0.0,1.0);
    glVertex3f(0,4,0);
    glEnd();
    glFlush();
}

