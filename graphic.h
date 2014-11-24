#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QtGui>
#include <QWidget>
#include <math.h>
#include "dot.h"

class Graphic : public QWidget
{
public:
    Graphic();
    QPainter painter;
    void paintEvent(QPaintEvent *pe);
    void timerEvent(QTimerEvent *event);
    int x;
    int y;
    int Radius;
    void Init();
    int currangle;
};

#endif // GRAPHIC_H
