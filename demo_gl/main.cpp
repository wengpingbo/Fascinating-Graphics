#include "gldemo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gldemo w;
    w.setWindowTitle(QObject::tr("OpenGL Demo"));
    w.resize(300,300);
    w.show();

    return a.exec();
}
