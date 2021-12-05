#include "MyFunctions.h"
#include <iostream>
#include <vector>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <Windows.h>
#include <cstdlib>
using namespace std;

void OutPut(const vector<char>& data)
{
	char num[200], num1[200];
    ofstream filestream("output.csv", ios::app);

	HANDLE hPipe = CreateNamedPipe(L"//.//pipe/num", PIPE_ACCESS_OUTBOUND, PIPE_TYPE_BYTE | PIPE_READMODE_BYTE,
		PIPE_UNLIMITED_INSTANCES, 1024, 1024, INFINITE, 0);
	HANDLE a = CreateFile(L"output.csv", GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, 0);
	ReadFile(a, num, sizeof(num1), 0, 0);
	WriteFile(hPipe, num, sizeof(num1), 0, 0);

	CloseHandle(hPipe);
	CloseHandle(a);

    copy(data.begin(), data.end(), ostream_iterator<char>(filestream, ";"));
    filestream.close();
}

void Separe()
{
    ofstream filestream("output.csv", ios::app);
    filestream << "\n";
    filestream.close();
}
