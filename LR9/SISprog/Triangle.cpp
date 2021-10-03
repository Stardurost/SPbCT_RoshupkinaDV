#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <widows.h>
#include "Triangle.h"

using namespace std;

//конструктор
Triangle::Triangle(Point _v1, Point _v2, Point _v3, const char* ident)
    : v1(_v1), v2(_v2), v3(_v3) {
    char buf[16];

    objID = new char[strlen(ident) + 1];
    strcpy(objID, ident);

    count++;

    sprintf(buf, "Треугольник %d", count);
    name = new char[strlen(buf) + 1];
    strcpy(name, buf);

    a = sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y));
    b = sqrt((v2.x - v3.x) * (v2.x - v3.x) + (v2.y - v3.y) * (v2.y - v3.y));
    с = sqrt((v1.x - v3.x) * (v1.x - v3.x) + (v1.y - v3.y) * (v1.y - v3.y));

    cout << "Конструктор_1 для: " << objID << "( " << name << " )" << endl;
}

// Конструктор пустого (нулевого) треугольника
Triangle::Triangle(const char* ident) {

    char buf[16];
    objID = new char[strlen(ident) + 1];
    strcpy(objID, ident);

    count++;
    sprintf(buf, "Треугольник %d", count);
    name = new char[strlen(buf) + 1];
    strcpy(name, buf);
    a = b = c = 0;
    cout << "Конструктор_2 для" << objID << " ( " << name << " )" << endl;
}
//Деструктор
Triangle::~Triangle() {
    cout << "Деструктор для: " << objID << endl;
    delete[]objID;
    delete[]name;
}

//Показать объект
void Triangle::Show() const {
    cout << name << ";";
    v1.Show(); v2.Show(); v3.Show();
    cout << endl;
}
// Показать стороны и площадь объекта
void Triangle::ShowSideAndArea()const {
    double p = (a + b + c) / 2;
    double s = sqrt(p * (p - a) * (p - b) * (p - c));
    cout << "----------------------------" << endl;
    cout << name << ";";
    cout.precision(4);
    cout << " a = " << setw(5) << a;
    cout << ". b = " << setw(5) << b;
    cout << ". c = " << setw(5) << c;
    cout << ";\ts = " << s << endl;

}