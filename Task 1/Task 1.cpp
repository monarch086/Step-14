/*
1. ������ � �������
*/

#define _CRT_SECURE_NO_WARNINGS

#include <io.h> //����� ����������
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
	int res = _access(path, 0); //�������� �� �������������: 0 - ��, 1 - ���

	int a = 15, b = 7, c = 3;

	if (res == 0) //���� ���� ����������
	{
		/*
		fputc
		fputs
		fwrite
		fprintf
		*/		
	}

	FILE *pt = fopen(path, "w"); //�������� ����� �� ���������� (��� ���������� � ����� ����� ������), �������� �����
	//pt = fopen(path, "a"); //�������� ����� �� ��������, �������� �����
	//pt = fopen(path, "r"); //�������� ����� �� ������

	fwrite(&a, sizeof(int), 1, pt);
	
	fclose(pt);
}