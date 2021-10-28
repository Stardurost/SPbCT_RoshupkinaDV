// ConsoleTriangle.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "TriangleLibrary.h"
#define M_PI 3.14159
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	double Square, Perimeter;			//площадь и периметр
	double temp1, temp2, temp3, temp4;  //временные переменные для упрощения кода
	double a, b, alfa;						//стороны треугольника
	cout << "Введите первую сторону треугольника: ";
	cin >> a;
	cout << "Введите вторую сторону треугольника: ";
	cin >> b;
	cout << "Введите угол между сторонами в градусах: ";
	cin >> alfa;
	Perimeter = temp1 = temp2 = temp3 = temp4 = 0;
	Perimeter = a + b;
	temp1 = TriangleFuncs::MyTriangleFuncs::Pow(a, 2);
	temp2 = TriangleFuncs::MyTriangleFuncs::Pow(b, 2);
	temp3 = TriangleFuncs::MyTriangleFuncs::Cos(alfa);
	temp4 = TriangleFuncs::MyTriangleFuncs::Square(temp1 + temp2 - 2 * a * b * temp3);
	Perimeter += temp4;

	Square = temp1 = temp2 = temp3 = temp4 = 0;
	temp1 =  TriangleFuncs::MyTriangleFuncs::Sin(alfa);
	Square = 0.5 * a * b * temp1;
	cout.precision(4);
		cout << "----------------------------------------------------------------------------------\n";
		cout << "Периметр треугольника равен: " << Perimeter << endl << "Площадь треугольника равна: " << Square<<"\n\n\n";
	return 0;
}
