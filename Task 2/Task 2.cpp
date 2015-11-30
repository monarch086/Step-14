/*
2. Работа с файлами: 
 - записать массив в файл;
 - чтение из файла.
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

	FILE *pt;
	
	double array[5] = {};
	for (int i = 0; i < 5; i++)
	{
		cout << "\n Введите " << i << "-й элемент: ";
		cin >> array[i];
	}

	pt = fopen(path, "a"); //открытие файла на дозапись, создание файла

	/*
	for (int i = 0; i < 5; i++)
	{
		fwrite(&array[i], sizeof(double), 1, pt);
	}
	*/

	fwrite(array, sizeof(double), 5, pt);

	fclose(pt);

	//~~~~~~~~~~ чтение файла ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	pt = fopen(path, "r"); //открытие файла на чтение
	fread(array, sizeof(double), 5, pt);

	for (int i = 0; i < 5; i++)
	{
		cout << array[i] << endl;
	}
	fclose(pt);
}