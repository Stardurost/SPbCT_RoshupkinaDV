#include "pch.h"
#include "Lorry.h"
//конструктор без параметров 
Lorry::Lorry(void):Car()
{
	gruz = 0;
}
//дескриптор
Lorry::~Lorry(void)
{
}
//конструктор с параметрами
Lorry::Lorry(string M, int C, int P, int G) :Car(M, C, P)
{
	gruz = G;
}
//конструктор копирования 
Lorry::Lorry(const Lorry &L)
{
	mark = L.mark;
	cyl = L.cyl;
	power = L.power;
	gruz = L.gruz;
}
//модификатор
void Lorry::Set_Gruz(int G)
{
	gruz = G;
} 
//оперция присваивания
Lorry& Lorry::operator=(const Lorry& l)
{
	if (&l == this)return *this;
	mark = l.mark;
	power = l.power;
	cyl = l.cyl;
	gruz = l.gruz;
	return *this;
}
//операция ввода
istream& operator>>(istream& in, Lorry& l)
{
	cout << "\nMark:"; in >> l.mark;
	cout << "\nPower:"; in >> l.power;
	cout << "\nCyl:"; in >> l.cyl;
	cout << "\nGruz:"; in >> l.gruz; return in;
}
//операция вывода
ostream& operator<<(ostream& out, const Lorry& l)
{
	out << "\nMARK : " << l.mark;
	out << "\nCYL : " << l.cyl;
	out << "\nPOWER : " << l.power;
	out << "\nGRUZ : " << l.gruz; out << "\n";
	return out;
}
