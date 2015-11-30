/*
4. ������ � �������:
- ������ � ���� � ������ �� ����� ��������� �����
*/

#define _CRT_SECURE_NO_WARNINGS

#include <io.h> //����� ����������
#include <iostream>

using namespace std;

struct Student
{
	char name[32];
	char surname[32];
	char sname [32];
};

void main()
{
	setlocale(LC_ALL, "Ukr");

	char *path = "student.txt";
	
	char name[32], surname[32], sname[32];
	cout << "\n ������� ���: ";
	cin >> name;
	cout << "\n ������� �������: ";
	cin >> surname;
	cout << "\n ������� ��������: ";
	cin >> sname;

	Student st;
	strcpy(st.name, name);
	strcpy(st.surname, surname);
	strcpy(st.sname, sname);

	FILE *pf = fopen(path, "w");
	
	fputs(name, pf);
	fputc(' ', pf);
	fputs(surname, pf);
	fputc(' ', pf);
	fputs(sname, pf);
	
	fclose(pf);

	int res = _access(path, 0); //�������� �� �������������: 0 - ��, 1 - ���
	
	if (res == 0) //���� ���� ����������
	{
		pf = fopen(path, "r");
		
		//char stack[48];
		//fgets(stack, 500, pf);
		//cout << stack << endl;

		Student st1 = {};
		int type = 0;
		int counter = 0;
		while (!feof(pf))
		{
			char c = fgetc(pf);
			if (c == ' ')
			{
				type++;
				counter = 0;
			}
			else if (type == 0)
			{
				st1.name[counter++] = c;
				st1.name[counter] = '\0';
			}
			else if (type == 1)
			{
				st1.surname[counter++] = c;
				st1.surname[counter] = '\0';
			}
			else if (type == 2)
			{
				st1.sname[counter++] = c;
				st1.sname[counter] = '\0';
			}
		}
		st1.sname[counter - 1] = '\0';//������� ���������� � ����� �����

		cout << "Our student: " << st1.name << ' ' << st1.surname << ' ' << st1.sname << endl;

		fclose(pf);
	}
}