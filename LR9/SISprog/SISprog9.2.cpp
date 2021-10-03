#include "pch.h"
#include <iostream>
#include <string>

// Подключения заголовочного файла с описанием класса Time
#include "Time.h"
// Подключение файлов для Triangle (Triangle & Point)
#include "Point.h"
#include "Triangle.h"

using namespace std;

int Menu();
int GetNumber(int, int);
void ExitBack();
void Show(Triangle* [], int);
void Move(Triangle* [], int);
void FindMax(Triangle* [], int);
void IsIncluded(Triangle* [], int);

// Инициализация глобальных переменных
int Triangle::count;
// Для числовой переменной, объявленной вне функций начальным значением будет 0.

int main()
{
    setlocale(LC_ALL, "ru");

    // Пример кода с использованием класса Time.
    Time t;
    t.setTime(16, 18, 20);
    t.printMilitary();
    cout << endl;
    t.printStandard();
    cout << endl;

    cout << Triangle::count;

    // Определения точек
    Point p1(0, 0); Point p2(0.5, 1);
    Point p3(1, 0); Point p4(0, 4.5);
    Point p5(2, 1); Point p6(2, 0);
    Point p7(2, 2); Point p8(3, 0);
    // Определения треугольников
    const char* nameA = "triaA";
    const char* nameB = "triaB";
    const char* nameC = "triaC";
    const char* nameD = "triaD";
    Triangle triaA(p1, p2, p3, nameA);
    Triangle triaB(p1, p4, p8, nameB);
    Triangle triaC(p1, p5, p6, nameC);
    Triangle triaD(p1, p7, p8, nameD);
    // Определение массива указателей на треугольники
    Triangle* pTria[] = { &triaA, &triaB, &triaC, &triaD }; int n = sizeof(pTria) / sizeof
    (pTria[0]);
    // Главный цикл
    bool done = false;
    while (!done)
    {
        switch (Menu())
        {
        case 1: Show(pTria, n); break;
        case 2: Move(pTria, n); break;
        case 3: FindMax(pTria, n); break;
        case 4: IsIncluded(pTria, n); break;
        case 5: cout << "Конец работы." << endl;
            done = true; break;
        }
    }
}

int Menu()
{
    cout << "\n===== Главное меню =====" << endl;
    cout << "1 - вывести все объекты\t 3 - найти максимальный" << endl;
    cout << "2 - переместить\t\t 4 - определить отношение включения" << endl;
    cout << "\t\t 5 - выход" << endl;
    return GetNumber(1, 5);
}

int GetNumber(int min, int max)
{
    int number = min - 1;
    while (true)
    {
        cin >> number;
        if ((number >= min) && (number <= max) && (cin.peek() == '\n')) {
            break;
        }
        else {
            cout << "Повторите ввод (ожидается число от " << min << " до " << max <<
                "):" << endl; cin.clear();
            while (cin.get() != '\n') {};
        }
    }
    return number;
}

void ExitBack()
{
    cout << "Нажмите Enter." << endl;
    cin.get(); cin.get();
}

void Show(Triangle* pTria[], int k)
{
    cout << "=== Перечень треугольников ===" << endl;
    for (int i = 0; i < k; i++) {
        pTria[i]->Show();
    }
    for (int i = 0; i < k; i++)
        pTria[i]->ShowSideAndArea();
    ExitBack();
}

void Move(Triangle* p_tria[], int k)
{
    cout << "======= Перемещение ======" << endl;
    // здесь будет код функции...
    ExitBack();
}

void FindMax(Triangle* p_tria[], int k)
{
    cout << "= Поиск максимального треугольника =" << endl;
    // здесь будет код функции...
    ExitBack();
}

void IsIncluded(Triangle* p_tria[], int k)
{
    cout << "===== Отношение включения =====" << endl;
    // здесь будет код функции...
    ExitBack();
}

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.