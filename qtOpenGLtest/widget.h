#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtOpenGL/qgl.h>       // !!!
#include <qgl.h>

#include <GL/gl.h>              // !!!
#include <GL/glu.h>             // !!!


namespace Ui {
class Widget;
}



// 修改控件的父类为QGLWidget
class Widget : public QGLWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();




private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
