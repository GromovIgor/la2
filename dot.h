#ifndef DOT_H
#define DOT_H

#include <math.h>
#include <QtGui>

class Dot                       //класс “очка
{
    int xPos;                   //текуща¤ коорд. х
    int yPos;                   //текуща¤ коорд. у
    int mas;                    //текущий масштаб
    qreal matrix[3][3];         //матрица транстф.
    void update();              //умножение коорд. на матрицу
    void clearmatrix();         //очищение матрицы
public:
    Dot(int x, int y);
    void setAngle(int angle);   //задание переноса
    void setPos(int x, int y);  //задание поворота
    int x();                    //получение коорд. х
    int y();                    //получение коорд. у
};

#endif // DOT_H
