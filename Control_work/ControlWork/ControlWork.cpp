#include "pch.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class Schedule								// описание класса
{
private:
	struct Person
	{
		Person* next;
		Person* previos;
		string name;
		int time;
		int day;
		int oms;
	};

	Person* First;  		// первый элемент 
	Person* Last; 			// последний элемент 


public:
	Schedule() { 														// присвоение значению начала и конца пустой ссылки 
		First = Last = NULL;
	};

	~Schedule() {														// деструктор
		while (First) {
			Last = First->next;
			delete First;
			First = Last;
		}
	};

	bool ExistTable();													// проверка на наличие записи  	
	bool CheckNote(int);  												// проверка существования записи в этот день и времени

	void ReadFile(ifstream&, Schedule&); 								// вывод информации из файла
	void SaveFile(ofstream&); 											// сохранение информации в файл

	void ShowDay();   													// вывод дня из расписания

	void Add(int, string, int, int);   									// добавление записи о приеме
	void Delete(int, string, int, int);  								// удаление записи о приеме

};

string DayInWeek(int);					    // вывод дня недели
string DayInWeek(int day)
{
	setlocale(LC_ALL, "ru");
	if (day < 8)
	{
		switch (day)
		{
		case 1: return "Понедельник";	break;
		case 2: return "Вторник";		break;
		case 3: return "Среда";			break;
		case 4: return "Четверг";		break;
		case 5: return "Пятница";		break;
		default: return "Выходной";
		}
	}
	else cout << "Ошибка ввода";
}			

void ReadFile(ifstream& file, Schedule* W)  // чтение файла
{
	string name, blank;
	int day, time, oms, c;
	if (!file)								// проверка на существование файла
	{
		cout << "Файл не найден \n";
		c = _getch();
	}
	else
	{
		while (!file.eof())						   // цикл пока не закончится файл
		{
			// ↓ загрузка в файл по очереди: день, время приема, имя пациента, номер полиса
			file >> day; file >> time; file >> name; file >> oms;
			W[day - 1].Add(day, name, time, oms);      // обращение к функции создания элемента списка
		}
		cout << "\nФайл записан\n";
		c = _getch();
		cout << blank;
	}
}   //чтение файла

void Schedule::SaveFile(ofstream& filecout)
{
	Person* temp = First;   // показ информации с первого элемента
	while (temp != NULL)	// пока не будет последний элемент
	{
		filecout << "\n";
		filecout << "          --------------------------\n";
		filecout << "	       |День приема: " << temp ->day << "\n";
		filecout << "	       |Время приема: " << temp->time << "\n";
		filecout << "	       |Фамилия пациента: " << temp->name << "\n";
		filecout << "	       |Полис ОМС:" << temp->oms << "\n";
		filecout << "          --------------------------\n";
		temp = temp->next;
	}
}

void Schedule::ShowDay()
{
	setlocale(LC_ALL, "ru");
	Person* temp = First;   // указатель на первый элемент
	while (temp != NULL)	// цикл пока не будет последнеей значение
	{

		cout << "\n";
		cout << "          --------------------------\n";
		cout << "	       |День приема: " << temp->day << "\n";
		cout << "	       |Время приема: " << temp->time << "\n";
		cout << "	       |Фамилия пациента: " << temp->name << "\n";
		cout << "	       |Полис ОМС:" << temp->oms << "\n";
		cout << "          --------------------------\n";
		
		temp = temp->next;
	}
}

void Schedule::Add(int DAY, string NAME, int TIME, int OMS)
{
	setlocale(LC_ALL, "ru");
	Person* person = new Person;		// создание элемента структуры
	int c;

	if ((TIME > 20 || TIME < 8) || (DAY > 5 || DAY < 1))	//проверка времени записи
	{
		cout << "\nНельзя выбрать это время. Режим работы поликлинники:\n";
		cout << "Пн, Вт, Ср, Чт, Пт - с 8 до 20\n\n\n";
	}
	else{
		person->day = DAY; person->time = TIME;		// присвоение значений элементам структуры
		person->name = NAME; person->oms = OMS;

		if (First == NULL)   						// условный оператор: если  списка ещё нет, то человек первый или последний
		{
			person->next = NULL; person->previos = NULL;
			First = Last = person;
			cout << "\nЗапись сохранена";
		}
		else
		{
			if (CheckNote(person->time))			//проверка записей на одинаковое время
			{
				Person* temp = First;				// присвоение текущему элементу первый элемент
				bool chek = true;
				bool checker = person->time == temp->time;

				if (person->time < temp->time)  	// если время новой записи меньше
				{
					First->previos = person;		// помещаем новую запись выше первого элемента
					person->previos = NULL;			// выше новой записи нет элементов
					person->next = First;			// ниже новой записи находится начало списка	
					First = person;					// теперь первая запись это последняя добавленная запись
				}
				else								 // если же новая запись позже
				{
					while (chek) {								// контроль выполнения цикла
						if (temp->next == NULL)                 // если текущий элемент последний
						{
							person->previos = temp;				// присваиваем новой записи место после текущего элемента
							person->next = NULL;				// следующее значение пустое, значит это последний элемент
							temp->next = person;				// текущий элемент становится перед новой записью			
							Last = person;						// присваиваем последнему элементу значение новой записи
							chek = 0;
						}
						else                                    // иначе
						{
							temp = temp->next;					// передвижение вниз по списку 
							if (person->time < temp->time)      // если новая запись раньше старой
							{
								person->next = temp;			// присваиваем значение новой записи выше текущей
								person->previos = temp->previos;// 
								temp->previos->next = person;
								temp->previos = person;			// новая запись становится раньше текущей 
								chek = 0;
							}
						}
					}
				}
				cout << " Запись сохранена\n";
				c = _getch();
			}
			else cout << "\nНа это время уже есть запись\n";
			c = _getch();
		}
	}
}

void Schedule::Delete(int D, string N, int T, int O)
{
	int c;
	if (First == NULL) { 
		cout << "Запись не найдена \n"; 
		c = _getch();
	} 
	else
	{
		if (First != Last) {
			bool key = true;
			Person* temp = First;
			while (key)
			{
				if (D == temp->day && N == temp->name && temp->time == T && O == temp->oms)  // проверка данных
				{
					if (temp == First){				 // если запись первая, то удаляем ее
						temp->next->previos = NULL;
						First = temp->next;
						delete temp;      
						key = false;
					}
					else
					{
						if (temp == Last){			// если запись является последней, то удаляем ее
							temp->previos->next = NULL;
							Last = temp->previos;
							delete temp;   
							key = false;
						}
						else{						// меняем местами записи, чтобы удалить запись посередине
							temp->previos->next = temp->next;	
							temp->next->previos = temp->previos;  
							delete temp;
							key = false;
						}
					}
				}
				else temp = temp->next;  
			}
		}
		else // если список содержит один элемент удаляем весь список
		{
			delete First;
			First = Last = NULL;
		}
		cout << "Запись удалена\n";
		c = _getch();

	}

}

bool Schedule::CheckNote(int timec) {	// поиск одинакового времени

	Person* element = First;		// указатель на первый элемент
	while (element != NULL) {		// цикл пока не дойдет до конца списка
		if (element->time == timec) // если элемент структуры time равен сравниваемому значению возврат 0 
			return 0;
		element = element->next;	// присвоение элементу следующего значения
	}
	return 1;
}

bool Schedule::ExistTable() {		// возврат 1, если список пуст, 0 если есть элементы
	
	if (First != NULL)
		return 0;
	else return 1;
}

void OpenMenu();							// вывод меню управления
void OpenMenu()   // Функция показа меню
{
	cout << "\n|  Расписание приема пациентов |\n";
	cout << "--------------------------------\n";
	cout << "  Список возможностей:\n";
	cout << "  1 - Показать расписание \n";
	cout << "  2 - Вывести расписание в файл\n";
	cout << "  3 - Загрузить расписание из файла\n";
	cout << "  4 - Показать записи на конкретный день\n";
	cout << "  5 - Добавить свою запись\n";
	cout << "  6 - Удалить запись пациента\n";
	cout << "  7 - Выход\n";
}

int main()
{
	Schedule Day1, Day2, Day3, Day4, Day5;               	 // создаём массив из элементов класса
	Schedule Days[5] = { Day1, Day2, Day3, Day4, Day5 };

	string name;
	int c, time, oms, key, day;
	setlocale(LC_ALL, "ru");
	cout << "   __           _                 _    _                  ___        \n";
	cout << "  /__\\ ___  ___| |__  _   _ _ __ | | _(_)_ __   __ _     /   \\/\\   /\\ \n";
	cout << " / \\/// _ \\/ __| '_ \\| | | | '_ \\| |/ / | '_ \\ / _` |   / /\\ /\\ \\ / / \n";
	cout << "/ _  \\ (_) \\__ \\ | | | |_| | |_) |   <| | | | | (_| |_ / /_//_ \\ V /  \n";
	cout << "\\/ \\_/\\___/|___/_| |_|\\__,_| .__/|_|\\_\\_|_| |_|\\__,_(_)___,'(_) \\_/   \n";
	cout << "                           |_|                                        ";
	cout << "\n\n";
	cout << "   ___            _             _   __    __           _    \n";
	cout << "  / __\\___  _ __ | |_ _ __ ___ | | / / /\\ \\ \\___  _ __| | __\n";
	cout << " / /  / _ \\| '_ \\| __| '__/ _ \\| | \\ \\/  \\/ / _ \\| '__| |/ /\n";
	cout << "/ /__| (_) | | | | |_| | | (_) | |  \\  /\\  / (_) | |  |   < \n";
	cout << "\\____/\\___/|_| |_|\\__|_|  \\___/|_|   \\/  \\/ \\___/|_|  |_|\\_\\\n";
	cout<<"\n\n\n";
	OpenMenu();
	cout << "Введите пункт меню.\n";
	key = _getch();
	cout << "\n";

	while (key != '7')		// цикл, пока пользователь не нажмёт 7	    
	{
		switch (key)		// выбор пункта меню
		{
		case '1':			// показать расписание
		{
			cout << "Раздел: Расписание на неделю\n";

			for (int i = 0; i < 5; i++)
			{
				cout << setw(15) << DayInWeek(i + 1) << "|  ";
				if (Days[i].ExistTable())
					cout << "В этот день никто не записан \n";
				else
					Days[i].ShowDay();
			}
			cout << setw(26) << "|Выходной|\n";
			cout << setw(26) << "|Выходной|\n";
			c = _getch();

		}; break;

		case '2':			// вывести в файл
		{
			cout << "Раздел: Выгрузка расписания в файл\n";
			ofstream f("outdata.txt");
			for (int i = 0; i < 5; i++)
			{
				f << setw(15) << DayInWeek(i + 1) << "|  ";
				if (Days[i].ExistTable())
					f << "В этот день никто не записан \n";
				else
					Days[i].SaveFile(f);
			}
			f << setw(26) << "|Выходной|\n";
			f << setw(26) << "|Выходной|\n";
			f.close();
			cout << "Файл сохранен.\n";
			c = _getch();
		}; break;

		case '3':			// загрузить из файла
		{
			cout << "Раздел: Загрузка расписания из файла\n";
			cout << "Требования к загружаемому файлу: \n";
			cout << "1. Название файла data \n";
			cout << "2. Расширение файла .txt\n";
			cout << "3. Данные вводятся в таком порядке: \n";
			cout << "          |Введите день приема:\n";
			cout << "          |Введите время приема:\n";
			cout << "          |Введите фамилию пациента:\n";
			cout << "          |Введите номер полиса ОМС:\n";
			cout << "4. Данные записываются через пробел \n";
			cout << "Нажмите любую клавишу, чтобы начать загрузку";
			c = _getch();
			ifstream r("data.txt");
			ReadFile(r, Days);
			r.close();
			c = _getch();
		}; break;

		case '4':			// конкретный день
		{
			cout << "Раздел: Запись на конкретный день\n";
			cout << "Введите день: ";
			cin >> day;
			cout << setw(15) << DayInWeek(day) << "|  ";

			if (Days[day - 1].ExistTable())
				cout << "Записей на этот день нет\n";
			else
				Days[day - 1].ShowDay();
			c = _getch();
		}; break;

		case '5':			// добавить запись
		{
			cout << "Раздел: Добавление новой записи\n";
			cout << "Цифра от 1 до 7, где:\n";
			cout << "	Понедельник - 1\n";
			cout << "	Вторник - 2\n";
			cout << "	Среда - 3\n";
			cout << "	Четверг - 4\n";
			cout << "	Пятница - 5\n";
			cout << "	Суббота - 6\n";
			cout << "	Воскресение - 7\n";
			cout << "Введите день приема:\n";
			cin >> day;
			cout << "Введите время приема. ";
			cout << "Введите количество часов: \n";
			cin >> time;
			cout << "Введите фамилию: ";
			cin >> name;
			cout << "Введите номер мед. полиса: ";
			cin >> oms;
			
			Days[day - 1].Add(day, name, time, oms);

		}; break;

		case '6':			// удалить
		{
			cout << "Раздел: Удаление записи пациента\n";
			cout << "Введите назначенный день приема: ";
			cin >> day;
			cout << "Введите время приема: ";
			cin >> time;
			cout << "Введите фамилию пациента: ";
			cin >> name;
			cout << "Введите номер ОМС: ";
			cin >> oms;

			Days[day - 1].Delete(day, name, time, oms);
			c = _getch();
		}; break;

		default:			// иначе неверная цифра
		{
			cout << "Некорректный ввод. Повторите попытку.\n";
		}; break;
		};

		OpenMenu();
		cout << "Введите пункт меню.\n";
		key = _getch();
		cout << "\n";
	}
	return 0;
}

