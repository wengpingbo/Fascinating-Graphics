#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPainter>
#include <QString>
#include <QMouseEvent>
#include <QtGlobal>
#include <QTime>
#include <QThread>
#include <QImage>
#include <QHBoxLayout>


class worker: public QThread
{
    Q_OBJECT
public:
    worker(QImage * image = 0);
signals:
    void imageReady();
private:
    QImage *image;
    void run();
};

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0);
    ~Window();
    void mouseMoveEvent(QMouseEvent *mevent);
    void paintEvent(QPaintEvent *event);
public slots:
    void renderImage();
private:
    worker *work;
    QImage *image;
};

#endif // WINDOW_H
