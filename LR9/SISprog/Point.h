#pragma once
#ifndef POINT_H
#define POINT_H

class Point {
public:
    //конструктор
    Point(double _x = 0, double _y = 0) :x(_x), y(_y) {}
    //Другие методы
    void Show() const;
public:
    double x, y;
};
#endif /*POINT_H*/
