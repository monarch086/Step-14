/*
2. ������ � �������: 
 - �������� ������ � ����;
 - ������ �� �����.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <io.h> //����� ����������
#include <iostream>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Ukr");

	char *path = "1.txt";
	int res = _access(path, 0); //�������� �� �������������: 0 - ��, 1 - ���

	FILE *pt;
	
	double array[5] = {};
	for (int i = 0; i < 5; i++)
	{
		cout << "\n ������� " << i << "-� �������: ";
		cin >> array[i];
	}

	pt = fopen(path, "a"); //�������� ����� �� ��������, �������� �����

	/*
	for (int i = 0; i < 5; i++)
	{
		fwrite(&array[i], sizeof(double), 1, pt);
	}
	*/

	fwrite(array, sizeof(double), 5, pt);

	fclose(pt);

	//~~~~~~~~~~ ������ ����� ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	pt = fopen(path, "r"); //�������� ����� �� ������
	fread(array, sizeof(double), 5, pt);

	for (int i = 0; i < 5; i++)
	{
		cout << array[i] << endl;
	}
	fclose(pt);
}