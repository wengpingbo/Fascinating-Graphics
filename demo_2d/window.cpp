#include "window.h"

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    this->setFixedSize(800, 600);
    this->setStyleSheet("QWidget {background-color:black;}");
    this->setMouseTracking(true);

    image = new QImage(this->size(), QImage::Format_ARGB32);
    image->fill(Qt::black);
    work = new worker(image);

    connect(work, SIGNAL(imageReady()), this, SLOT(renderImage()));

    //initialize random seed for qrand() function
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    work->start();
}

Window::~Window()
{

}

worker::worker(QImage *image)
{
    this->image = image;
}

void worker::run()
{
    int seed;
    qreal x = 0, y = 0, x1, y1;

    QPainter *painter = new QPainter(image);
    //painter->begin();
    painter->setPen(QColor("white"));
    painter->setRenderHint(QPainter::Antialiasing, true);
    //painter->setBackground();

    //change this value if you want to draw more intensive points
    long long count = 50000;
    while(count > 0)
    {
        seed = qrand() % 3;
        switch(seed)
        {
        case 0:
            x1 = 0.5 * x;
            y1 = 0.5 * y;
            break;
        case 1:
            x1 = 0.5 * x + 0.5;
            y1 = 0.5 * y;
            break;
        case 2:
            x1 = 0.5 * x + 0.5;
            y1 = 0.5 * y + 0.5;
            break;
        }
        //qDebug("x : %f  y: %f", x1, y1);
        x = x1; y = y1;
        x1 = 600 * x1;
        y1 = 600 * y1;
        painter->drawPoint(QPointF(y1, x1));
        count--;
        this->msleep(1);
        emit imageReady();
    }
}

void Window::mouseMoveEvent(QMouseEvent *mevent)
{
    QString str = QString("X: %1  Y: %2").arg(mevent->pos().x()).arg(mevent->pos().y());
    this->setWindowTitle(str);
}

void Window::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(0,0,*image);
}

void Window::renderImage()
{
    this->update();
}
