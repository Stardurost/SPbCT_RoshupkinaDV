#include "pch.h"
#include "MyFunctions.h"
#include <thread>
#include <iostream>
#include <string>
#include <fstream>  
#include <iostream>   
#include <vector> 
#include <windows.h>
#include <ctime>
#include <time.h>

using namespace std;
vector<char> v1, v2, v3, v4, v5, v6, v7, v8, v9, v10;
vector <char> vec[10] = { v1, v2, v3, v4, v5, v6, v7, v8, v9, v10 };
char StringA, StringB;


void ThreadA() {
	ifstream file;
	file.open("data.txt");
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			file >> StringA;
			vec[i].push_back(StringA);
			sort(vec[i].begin(), vec[i].end());
			replace(vec[i].begin(), vec[i].end(), '6', '@');
			OutPut(vec[i]);
			vec[i].clear();
		}
		Separe();
	}
	file.close();
}

void ThreadB() {
	
	ifstream file;
	
	file.open("data.txt");
	for (int j = 5; j < 10; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			file >> StringB;
			vec[i].push_back(StringB);
			sort(vec[i].begin(), vec[i].end());
			replace(vec[i].begin(), vec[i].end(), '9', '*');
			OutPut(vec[i]);
			vec[i].clear();
		}
		Separe();
	}
	file.close();
}

int main(){
	
	setlocale(LC_ALL, "ru");

	// вывод имени 
	cout << "   __           _                 _    _                  ___        \n";
	cout << "  /__\\ ___  ___| |__  _   _ _ __ | | _(_)_ __   __ _     /   \\/\\   /\\ \n";
	cout << " / \\/// _ \\/ __| '_ \\| | | | '_ \\| |/ / | '_ \\ / _` |   / /\\ /\\ \\ / / \n";
	cout << "/ _  \\ (_) \\__ \\ | | | |_| | |_) |   <| | | | | (_| |_ / /_//_ \\ V /  \n";
	cout << "\\/ \\_/\\___/|___/_| |_|\\__,_| .__/|_|\\_\\_|_| |_|\\__,_(_)___,'(_) \\_/   \n";
	cout << "                           |_|                                        ";
	cout << "\n\n";

	// вывод времени
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	cout <<  asctime(timeinfo) << endl;

	// работа с потоками
	thread tA(ThreadA);
	tA.join();
	thread tB(ThreadB);
	tB.join();
	
	cout << "The file was create!\n";
}
