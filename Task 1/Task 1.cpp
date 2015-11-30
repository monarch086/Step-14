/*
1. Работа с файлами
*/

#define _CRT_SECURE_NO_WARNINGS

#include <io.h> //новая библиотека
#include <iostream>
#include <string.h>
#include <conio.h>
#include <time.h>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Ukr");
	srand(time(NULL));

	char *path = "1.txt";
	int res = _access(path, 0); //проверка на существование: 0 - да, 1 - нет

	int a = 15, b = 7, c = 3;

	if (res == 0) //если файл существует
	{
		/*
		fputc
		fputs
		fwrite
		fprintf
		*/		
	}

	FILE *pt = fopen(path, "w"); //открытие файла на перезапись (вся информация в файле будет стерта), создание файла
	//pt = fopen(path, "a"); //открытие файла на дозапись, создание файла
	//pt = fopen(path, "r"); //открытие файла на чтение

	fwrite(&a, sizeof(int), 1, pt);
	
	fclose(pt);
}