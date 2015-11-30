/*
3. Работа с файлами:
- чтение из файла неизвестного размера.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <io.h> //новая библиотека
#include <iostream>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Ukr");

	char *path = "1.txt";
	int res = _access(path, 0); //проверка на существование: 0 - да, 1 - нет
	
	if (res == 0) //если файл существует
	{
		int size = 100;
		double *x = new double[size];
		
		FILE *pf = fopen("1.txt", "r");
		double *y = x;

		while (!feof(pf))
		{
			fread(y, sizeof(double), 1, pf);
			cout << *y++ << ", ";
		}

		delete[] x;
		fclose(pf);
	}
}