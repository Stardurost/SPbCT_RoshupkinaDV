#include "pch.h"
#include <iostream>
using namespace std;
class Time
{
public:
	//Time();
	void setTime(int, int, int);		//��������� �����, ����� � ������
	void printMilitary();				//������ ������� � ������� �������
	void printStandard();				//������ ������� � ����������� �������
private:
	int hour;							//0-23
	int minute;							//0-59
	int second;							//0-59
};

void Time::setTime(int h, int m, int s)
{
	hour = (h >= 0 && h < 24) ? h : 0;
	minute = (m >= 0 && m < 60) ? m : 0;
	second = (s >= 0 && s < 60) ? s : 0;
}
//������ ������� � ������� �������
void Time::printMilitary()
{
	cout << (hour < 1 ? "0" : "") << hour << ":" << (minute < 1 ? "0" : "") << minute << ":" << (second < 1 ? "0" : "") << second;
}
//������ ������� � ����������� �������
void Time::printStandard()
{
	cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":" << (minute < 1 ? "0" : "") << minute << ":" << (second < 1 ? "0" : "") << second << (hour < 12 ? "AM" : " PM");
}
//������������ �������� �������� ������ Time
int main()
{
	setlocale(LC_ALL, "ru");
	Time t; //����������� ���������� ������� t ������ Time
	cout << "��������� �������� �������� ������� ����� ";
	t.printMilitary();
	cout << endl << "��������� �������� ������������ ������� ����� ";
	t.printStandard();
	t.setTime(13, 27, 6);
	cout << endl << endl << "������� ����� ����� setTime ����� ";
	t.printMilitary();
	cout << endl << "����������� ����� ����� setTime ����� ";
	t.printStandard();
	t.setTime(99, 99, 99);//������� ���������� ������������ ��������
	cout << endl << endl << "����� ������� ������������ ���������: " << endl << "������� �����: ";
	t.printMilitary();
	cout << endl << "����������� �����: ";
	t.printStandard();
	cout << endl;
	system("Pause");
	return 0;

}
