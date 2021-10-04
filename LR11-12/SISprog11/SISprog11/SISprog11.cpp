#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

template <class T>
class Mas					
{
	int size;
	T* m;
public:
	Mas(int size)		
	{
		this->size = size;
		m = new T[size];
	}

	~Mas()				
	{
		delete[] m;
	}

	Mas(const Mas& a)		
	{
		size = a.size;
		m = new T[size];
		for (int i = 0; i < a.size; i++)
		{
			m[i] = a.m[i];
		}
	}

	void GetMas(int i, T obj)	  //ввод
	{
		m[i] = obj;
	}

	void ShowMas()					//вывод
	{
		for (int i = 0; i < size; i++)
		{
			cout << m[i] << " ";
		}
		cout << endl;
	}

	Mas& operator=(const Mas& B)		// перегрузка присваивания
	{

		for (int i = 0; i < B.size; i++)
		{
			m[i] = B.m[i];
		}
		return *this;
	}

	Mas& operator-(Mas C)				//перегрузка вычитания
	{
		for (int i = 0; i < C.size; i++)
		{
			m[i] = m[i] - C.m[i];
		}
		return *this;
	}

	Mas& operator-(T i)					//перегрузка вычитания элемента
	{
		m[size - 1] = m[size - 1] - i;
		return *this;
	}

};

class Test
{
public:
	Test(int _x = 0, int _y = 0) : x(_x), y(_y) {}

	void ShowMas() const			//функция вывода точки
	{
		cout << " (" << x << "," << y << ")" << endl;
	}
	Test(const Test& copy)			//конструктор копирования
	{
		x = copy.x;
		y = copy.y;
	}

	Test& operator =(const Test& a)	//оператор присваивания
	{
		x = a.x;
		y = a.y;
		return *this;
	}

	const Test operator -(const Test& a)	//оператор вычитания
	{

		return Test(x - a.x, y - a.y);
	}
	int x, y;

	friend ostream& operator<< (ostream& out, const Test& Test);
};

ostream& operator<< (ostream& out, const Test& Test)
// перегрузка оператора вывода для класса Test
{
	out << " (" << Test.x << "," << Test.y << ")";
	return out;
}

int main()
{
	setlocale(LC_ALL, "ru");
	Mas <double> A(10);
	cout << endl;
	cout << "	Mas A(10)" << endl;

	for (int i = 0; i < 10; i++)
	{
		A.GetMas(i, i + 1);
	}

	A.ShowMas();
	cout << endl;
	cout << "	Mas A = B " << endl;
	Mas <double> B = A;
	

	B.ShowMas();
	cout << endl;
	cout << "	Mas C = B - A " << endl;
	Mas <double> C(10);
	C = B - A;

	C.ShowMas();
	cout << endl;
	cout << "	Mas C = C - 5 " << endl;
	C = C - 5;
	C.ShowMas();

	Mas <Test> A1(10);
	cout << endl;
	cout << "	Mas A1(10)" << endl;
	for (int i = 0; i < 10; i++)
	{
		A1.GetMas(i, Test(i + 1, i));
	}

	A1.ShowMas();
	cout << endl;
	cout << "	Mas B1 = A1 " << endl;
	Mas <Test> B1 = A1;

	B1.ShowMas();
	cout << endl;
	cout << "	Mas C1 = B1 - A1 " << endl;
	Mas <Test> C1(10);
	C1 = B1 - A1;

	C1.ShowMas();
	cout << endl;
	cout << "	Mas C1 = C1 - Test(50, 50) " << endl;
	C1 = C1 - Test(50, 50);
	C1.ShowMas();
}