#include "pch.h"
#include "MyFunctions.h"
#include <iostream>
#include <vector>
using namespace std;

void OutPut(const vector<char>& data)
{
    ofstream filestream("output.csv", ios::app);
    copy(data.begin(), data.end(), ostream_iterator<char>(filestream,";"));
    filestream.close();
}

void Separe()
{
    ofstream filestream("output.csv", ios::app);
    filestream << "\n";
    filestream.close();
}
