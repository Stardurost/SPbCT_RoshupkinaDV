#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	double s, expenditure, cost;		   //���������� ����������
	// ���� � ������ �������� ����������
	cout << "������� ���������� ";
		cin >> s;
	cout << "������� ������ ������� ";
		cin >> expenditure;
	cout << "������� ���� ������� �������  ";
		cin >> cost;
		double	sum = 0;			    	// �������� ����������
		sum = s * expenditure * cost / 100;
		cout.precision(4);					// ��������� ����� �� 2�� ������ ����� �������
		cout << "��������� ������� ���������� "<< sum;
	return 0;
}
