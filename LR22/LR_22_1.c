#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t child;						// объявление переменной child типа данных pid_t
    int fd;
    char* args[] = { "ps", NULL };		// объявление строковой переменной 	args

    fd = open("out.txt", O_WRONLY | O_CREAT | O_TRUNC); //открытие файла out.txt функцией open
    if (fd == -1)						//условный оператор, если результат функции open = -1
    {
        perror("open()");				//выводит ошибку, перед ней строку open()
        exit(EXIT_FAILURE);				//вызывает завершение программы
    }
    if (dup2(fd, STDOUT_FILENO) == -1)
    {
        perror("dup2()");
        exit(EXIT_FAILURE);
    }

    child = fork();						//присовение переменной child результата выполнения системной функции fork()=0 или fork()=-1
    if (child == -1)					//если функция вернула значение ошибки, тогда 
    {
        perror("fork()");				//выводим сообщение об ошибке
        exit(EXIT_FAILURE);				//вызывает завершение программы
    }
    if (child == 0)						//если функция вернула значение не ошибки, тогда 
    {
        sleep(1);						
        execvp("ps", args);				// запуск файла на выполнение
    }
    wait(NULL);
    execvp("ps", args);
    return 0;
}