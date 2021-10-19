#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	double s, expenditure, cost;		   //объ€вление переменных
	// ввод с экрана значений переменной
	cout << "¬ведите километраж ";
		cin >> s;
	cout << "¬ведите расход топлива ";
		cin >> expenditure;
	cout << "¬ведите цену единицы топлива  ";
		cin >> cost;
		double	sum = 0;			    	// итогова€ переменна€
		sum = s * expenditure * cost / 100;
		cout.precision(4);					// форматный вывод до 2ух знаков после зап€той
		cout << "—тоимость поездки составл€ет "<< sum;
	return 0;
}
