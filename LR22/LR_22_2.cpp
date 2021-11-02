#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <fstream>
using namespace std;
int main()
{

ofstream text;						//начало работы с файлом
text.open("out_2.txt");				//открыть файл
int var, pid;
var=1;
text << "var = " << var << endl;
var+=1;
text << "Var increment: " << var <<endl;
pid=fork();							//присвоение переменной pid значения сист. функции 
if(pid == 0){						//если значение не равно ошибке, тогда вывод результата сложения
text << "\nChild process:\nvar before = " << var << endl;
var += 5;
text << "var after = "<< var << endl;
}
else if(pid > 0){
text << "\nParent process:\nvar before = " << var << endl;
var += 3;
text << "var after = " << var << endl;
wait((int *)pid); 
}
else {						       //иначе вывод ошибки и вовзрат значения -1
perror("Fork error ");
return -1;
}
return 0;
}
