#pragma once 
#include <string>
#include <iostream>
using namespace std; 

class Car {

public:
	Car(void);
	virtual ~Car(void);			//деструктор
	Car(string, int, int);		//констрктор с параметрами
	Car(const Car&);			//конструктор копирования 
	string Get_markHlreturn() {return mark; } 
	int Get_cyl() { return cyl; } 
	int Get_power() { return power; }	//модификаторы
	void Set_mark(string); 
	void Set_cyl(int); 
	void Set_power(int);
	
	Car& operator=(const Car&);		//перегрузка операции присваивания
	
	//глобальные операторы-функции ввода-вывода
	friend istream& operator>>(istream& in, Car& c); 
	friend ostream& operator<<(ostream& out, const Car& c); 
	//атрибуты protected:

	string mark; 
	int cyl;
	int power;
};

