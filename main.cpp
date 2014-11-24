#include <QtGui>
#include <QApplication>
#include "graphic.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Graphic window;
    window.show();
    return app.exec();
}
