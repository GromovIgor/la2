#include "dot.h"

Dot::Dot(int x, int y)      //конструктор класса
{
 clearmatrix();
 xPos = x;
 yPos = y;
 mas = 1;
}

void Dot::clearmatrix()     //задание единичной матрицы
{
    for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
           matrix[i][j] = 0;
    for (int i = 0; i < 3; i++) matrix[i][i] = 1;
}


void Dot::update()      //умножение матрицы на координаты
{
    int x;
    int y;
    x = xPos * matrix[0][0] + yPos * matrix[1][0] + mas * matrix[2][0];
    y = xPos * matrix[0][1] + yPos * matrix[1][1] + mas * matrix[2][1];
    mas =  xPos * matrix[0][2] + yPos * matrix[1][2] + mas * matrix[2][2];
    xPos = x;
    yPos = y;
    clearmatrix();
}

int Dot::x()
{
   return xPos/mas;
}

int Dot::y()
{
   return yPos/mas;
}

void Dot::setPos(int x, int y)
{
    matrix[2][0] = x;
    matrix[2][1] = y;
    update();
}

void Dot::setAngle(int angle)
{
    matrix[0][0] = cos(angle*M_PI/180);
    matrix[0][1] = sin(angle*M_PI/180);
    matrix[1][0] = -1 * sin(angle*M_PI/180);
    matrix[1][1] = cos(angle*M_PI/180);
    update();
}


