#ifndef GLDEMO_H
#define GLDEMO_H

#include <QtOpenGL>
#include <QtGUI>
#include <GL/glu.h>

class gldemo : public QGLWidget
{
    Q_OBJECT

public:
    gldemo(QGLWidget *parent = 0);
    ~gldemo();
protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
private:
    void draw();
    int faceAtPosition(const QPoint &pos);
    GLfloat rotationX;
    GLfloat rotationY;
    GLfloat rotationZ;
    QColor faceColors[4];
    QPoint lastPos;
};

#endif // GLDEMO_H
