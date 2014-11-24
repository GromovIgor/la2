#include "graphic.h"

Graphic::Graphic()
{
    currangle = 0;                              //текущий угол поворота колеса
    this->startTimer(1000/24);                  //таймер + время смены кадра

    /*задание белого фона для формы*/
    QPalette pal;
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);
}

 void Graphic::timerEvent(QTimerEvent *event)   //время таймера истекло
{
    currangle++;                                //увеличить угол колеса на 1 градус
    repaint();                                  //перерисовать колесо
}

void Graphic::Init()                            //получение данных о форме
{
    int height;
    int width;

    height = this->height();
    width = this->width();

    x = width / 2;                              //центр экрана...
    y = height / 2;                             //...или центр области рисования
    Radius = width < height? width/2-50: height/2-50;
}

void Graphic::paintEvent(QPaintEvent *pe)       //рисование колеса
{
    int n = 6;                                  //кол-во кабинок
    int angle = 360 / n;                        //углы между кабинками
    
    Init();
    painter.begin(this);
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine));      //цвет линии
    painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));  //цвет заливки
    painter.setRenderHint(QPainter::Antialiasing, true);    //сглаживание on

     for (int i = 0; i < n; i++)                            //обрисовка колеса
    {
        Dot M(0,0);                                 //точка на крыше кабинки
        Dot A(-1*Radius/14,Radius/14);              //еще две...
        Dot B(Radius/14,Radius/14);                 //...точки кабинки

        M.setPos(0,Radius);                         //перенос вершины кабинки
        M.setAngle(currangle+i*angle);              //поворот вершины относительно (0,0)
        M.setPos(x,y);                              //перенос вершины

        A.setPos(M.x(),M.y());                      //перенос двух...
        B.setPos(M.x(),M.y());                      //...оставшихся точек

        painter.drawLine(x,y,M.x(),M.y());          //рисование оси от центра к кабинке

        QPolygon poly;
        poly << QPoint(M.x(),M.y())<< QPoint(A.x(),A.y()) << QPoint(B.x(),B.y()) ;
        painter.drawPolygon(poly);                  //рисование крышечки
        painter.drawRect(QRect(A.x(),A.y(),Radius/7,Radius/7)); //рисование основания кабинки

        painter.drawEllipse(QPoint(M.x(),M.y()),Radius/70,Radius/70);   //рисование сцепления кабинки и оси
    }
    painter.end();
}
