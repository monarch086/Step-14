/*
3. ������ � �������:
- ������ �� ����� ������������ �������.
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
	
	if (res == 0) //���� ���� ����������
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