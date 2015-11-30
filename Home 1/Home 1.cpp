/*
� ����������� ��������� ������� � ��������� �������� ����������� �������� ������ � �����.
��� ������� ��������� ��� ������ ������ ����������� �� �����, � ��� �������� ���������, ��� ������ ������ �����������.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <io.h>

using namespace std;

struct Student
{
	char name[32];
	char surname[32];
	int age;
	float averageGrade;
};

struct Group
{
	char name[32];
	Student *students;
	int quantity;
};

struct Lecturer
{
	char name[32];
	char surname[32];
};

struct Academy
{
	Group *groups;
	int groupQuantity;
	Lecturer *lecturers;
	int lectQuantity;
};

enum StudentSort
{
	bySurname = 0,
	byAge = 1
};

enum GroupSort
{
	byAverage = 0,
	byQuantity = 1
};

void initializeAcademy(Academy &academy);
void removeAcademy(Academy &academy);
void showAcademy(Academy &academy);
void showGroups(Academy &academy);
void showStudentsOfGroup(Group &group);
void showLecturers(Academy &academy);
void addGroup(Academy &academy, char *name);
void addStudent(Group &group, char *name, char *surname, int age);
void addLecturer(Academy &academy, char *name, char *surname);
void removeStudent(Group &group, int student);
void removeLecturer(Academy &academy, int lecturer);
void removeGroup(Academy &academy, int group);
void transferStudent(Group &origin, Group &destination, int student);
void sortGroups(Academy &academy, GroupSort type);
void sortStudents(Group &group, StudentSort type);
bool compStud(Student arraySt, Student compSt, StudentSort type);
void mixStudents(Group &group);
bool compGroup(Group arrayGr, Group compGr, GroupSort type);
float getAverage(Group group);
void saveAcademy(Academy &academy);
void loadAcademy(Academy &academy);

void main()
{
	setlocale(LC_ALL, "Ukr");
	srand(time(NULL));

	Academy Step = {};

	loadAcademy(Step);

	showAcademy(Step);

	int a = 0;
	while (a != 27)
	{
		cout << "�������� ��������:" << endl;
		cout << "q - �������� ��� ��������" << endl;
		cout << "w - �������� �������� ����� ��������" << endl;
		cout << "e - �������� �������� ��������� ������" << endl;
		cout << "a - �������� ������" << endl;
		cout << "s - �������� �������� � ������" << endl;
		cout << "d - �������� �������������" << endl;
		cout << "f - ������� ������" << endl;
		cout << "g - ������� ��������" << endl;
		cout << "h - ������� �������������" << endl;
		cout << "j - ��������� �������� � ������ ������" << endl;
		cout << "z - ����������� ������ �� �������� ����� ���������" << endl;
		cout << "x - ����������� ������ �� ���������� ���������" << endl;
		cout << "c - ����������� ��������� ������ �� �������" << endl;
		cout << "v - ����������� ��������� ������ �� ��������" << endl;
		cout << "b - ���������� ��������� ������" << endl;

		char symb;
		cin >> symb;

		switch (symb)
		{
		case 'q':
		{
					cout << "~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~" << endl;
					cout << "�������� ��� ��������" << endl;
					showAcademy(Step);
					break;
		}
		case 'w':
		{
					cout << "~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~" << endl;
					cout << "�������� �������� �����" << endl;
					showGroups(Step);
					break;
		}
		case 'e':
		{
					cout << "~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~" << endl;
					cout << "�������� ��������� ������" << endl;
					cout << "�������� ������ ��� ����������� ���������:" << endl;
					showGroups(Step);
					int group;
					cin >> group;
					showStudentsOfGroup(Step.groups[group - 1]);
					break;
		}
		case 'a':
		{
					cout << "~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~" << endl;
					cout << "���������� ������" << endl;
					cout << "������� �������� ����� ������: " << endl;
					char name[32];
					cin >> name;
					addGroup(Step, name);
					showGroups(Step);
					break;
		}
		case 's':
		{
					cout << "~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~" << endl;
					cout << "���������� ��������" << endl;
					cout << "�������� ������ ��� ���������� ��������:" << endl;
					showGroups(Step);

					int group;
					cin >> group;

					cout << "������� ��� ��������: ";
					char name[32];
					cin >> name;

					cout << "\n������� ������� ��������: ";
					char surname[32];
					cin >> surname;

					cout << "\n������� ������� ��������: ";
					int age;
					cin >> age;
					cout << endl;

					addStudent(Step.groups[group - 1], name, surname, age);
					showStudentsOfGroup(Step.groups[group - 1]);
					break;
		}
		case 'd':
		{
					cout << "~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~" << endl;
					cout << "���������� �������������" << endl;
					cout << "������� ��� �������������: ";
					char name[32];
					cin >> name;

					cout << "\n������� ������� �������������: ";
					char surname[32];
					cin >> surname;

					addLecturer(Step, name, surname);
					showLecturers(Step);
					break;
		}
		case 'f':
		{
					cout << "~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~" << endl;
					cout << "�������� ������" << endl;

					cout << "�������� ������:" << endl;
					showGroups(Step);
					int group;
					cin >> group;

					removeGroup(Step, group - 1);
					showGroups(Step);
					break;
		}
		case 'g':
		{
					cout << "~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~" << endl;
					cout << "�������� ��������" << endl;

					cout << "�������� ������:" << endl;
					showGroups(Step);
					int group;
					cin >> group;

					cout << "�������� ��������:" << endl;
					showStudentsOfGroup(Step.groups[group - 1]);
					int stud;
					cin >> stud;

					removeStudent(Step.groups[group - 1], stud - 1);
					showStudentsOfGroup(Step.groups[group - 1]);
					break;
		}
		case 'h':
		{
					cout << "~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~" << endl;
					cout << "�������� �������������" << endl;

					cout << "�������� �������������:" << endl;
					showLecturers(Step);
					int lect;
					cin >> lect;

					removeLecturer(Step, lect - 1);
					showLecturers(Step);
					break;
		}
		case 'j':
		{
					cout << "~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~" << endl;
					cout << "������� ��������" << endl;

					cout << "�������� ������, � ������� ������ �������:" << endl;
					showGroups(Step);
					int origin;
					cin >> origin;

					cout << "�������� ��������:" << endl;
					showStudentsOfGroup(Step.groups[origin - 1]);
					int stud;
					cin >> stud;

					cout << "�������� ������ ����������:" << endl;
					showGroups(Step);
					int destination;
					cin >> destination;

					transferStudent(Step.groups[origin - 1], Step.groups[destination - 1], stud - 1);
					showStudentsOfGroup(Step.groups[origin - 1]);
					showStudentsOfGroup(Step.groups[destination - 1]);
					break;
		}
		case 'z':
		{
					cout << "~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~" << endl;
					cout << "���������� ����� �� �������� ����� ���������" << endl;

					sortGroups(Step, byAverage);
					showAcademy(Step);
					break;
		}
		case 'x':
		{
					cout << "~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~" << endl;
					cout << "���������� ����� �� ���������� ���������" << endl;

					sortGroups(Step, byQuantity);
					showAcademy(Step);
					break;
		}
		case 'c':
		{
					cout << "~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~" << endl;
					cout << "���������� ��������� ������ �� �������" << endl;

					cout << "�������� ������:" << endl;
					showGroups(Step);
					int group;
					cin >> group;

					sortStudents(Step.groups[group - 1], bySurname);
					showStudentsOfGroup(Step.groups[group - 1]);
					break;
		}
		case 'v':
		{
					cout << "~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~" << endl;
					cout << "���������� ��������� ������ �� ��������" << endl;

					cout << "�������� ������:" << endl;
					showGroups(Step);
					int group;
					cin >> group;

					sortStudents(Step.groups[group - 1], byAge);
					showStudentsOfGroup(Step.groups[group - 1]);
					break;
		}
		case 'b':
		{
					cout << "~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~ ~~~" << endl;
					cout << "������������� ��������� ������" << endl;

					cout << "�������� ������:" << endl;
					showGroups(Step);
					int group;
					cin >> group;

					mixStudents(Step.groups[group - 1]);
					showStudentsOfGroup(Step.groups[group - 1]);
					break;
		}
		}

		cout << endl;
		cout << "��� ����������� ������i�� ����-��� ����i�� ��i� Esc: " << endl;
		a = _getch();
	}

	saveAcademy(Step);
	removeAcademy(Step);
	cout << "Academy is deleted" << endl;
}

void initializeAcademy(Academy &academy)
{
	const int GROUPSQUANT = 3;
	const int STUDENTSQUANT = 10;
	const int LECTURERSQUANT = 5;

	//������� � ��������� ������ �����
	academy.groups = new Group[GROUPSQUANT];
	academy.groupQuantity = GROUPSQUANT;
	for (int i = 0; i < GROUPSQUANT; i++)
	{
		strcpy(academy.groups[i].name, "Group");
		academy.groups[i].quantity = STUDENTSQUANT;
		academy.groups[i].students = new Student[STUDENTSQUANT];

		for (int j = 0; j < STUDENTSQUANT; j++)
		{
			academy.groups[i].students[j].age = rand() % 7 + 18;
			academy.groups[i].students[j].averageGrade = 70 + rand() % 25 + (rand() % 100) / 100.0;
			strcpy(academy.groups[i].students[j].name, "Student");
			strcpy(academy.groups[i].students[j].surname, "Surname");
		}
	}

	//������� � ��������� ������ ��������������
	academy.lectQuantity = LECTURERSQUANT;
	academy.lecturers = new Lecturer[LECTURERSQUANT];
	for (int i = 0; i < LECTURERSQUANT; i++)
	{
		strcpy(academy.lecturers[i].name, "Lecturer");
		strcpy(academy.lecturers[i].surname, "Surname");
	}
}

void removeAcademy(Academy &academy)
{
	for (int i = 0; i < academy.groupQuantity; i++)
	{
		if (academy.groups[i].quantity > 0)
			delete[] academy.groups[i].students;
	}

	delete[] academy.groups;
	delete[] academy.lecturers;
}

void showAcademy(Academy &academy)
{
	cout << "Academy:" << endl;
	cout << "Number of groups: " << academy.groupQuantity << endl << endl;
	for (int i = 0; i < academy.groupQuantity; i++)
	{
		cout << "\t" << academy.groups[i].name << ": " << academy.groups[i].quantity << " students" << endl;
		for (int j = 0; j < academy.groups[i].quantity; j++)
		{
			cout << "\t" << academy.groups[i].students[j].name << ' ';
			cout << academy.groups[i].students[j].surname << ", ";
			cout << academy.groups[i].students[j].age;
			cout << " ���, ������� ����: " << academy.groups[i].students[j].averageGrade << endl;
		}
		cout << endl;
	}

	cout << "Number of lecturers: " << academy.lectQuantity << endl;
	for (int i = 0; i < academy.lectQuantity; i++)
	{
		cout << "\t" << academy.lecturers[i].name << " ";
		cout << academy.lecturers[i].surname << endl;
	}
}

void showGroups(Academy &academy)
{
	cout << "Groups of Academy:" << endl;
	for (int i = 0; i < academy.groupQuantity; i++)
	{
		cout << i + 1 << ". " << academy.groups[i].name << endl;
	}
}

void showStudentsOfGroup(Group &group)
{
	cout << "�������� ������ " << group.name << ':' << endl;
	for (int i = 0; i < group.quantity; i++)
	{
		Student st = group.students[i];
		cout << i + 1 << ". " << st.name << ' ' << st.surname << ", " << st.age << " ���, ������� ����: " << st.averageGrade << endl;
	}

	if (group.quantity == 0)
		cout << "�����������" << endl;
}

void showLecturers(Academy &academy)
{
	cout << "�������������:" << endl;
	for (int i = 0; i < academy.lectQuantity; i++)
	{
		Lecturer l = academy.lecturers[i];
		cout << i + 1 << ". " << l.name << ' ' << l.surname << endl;
	}

	if (academy.lectQuantity == 0)
		cout << "�����������" << endl;
}

void addGroup(Academy &academy, char *name)
{
	Group *old = academy.groups;
	academy.groupQuantity++;
	academy.groups = new Group[academy.groupQuantity];
	for (int i = 0; i < academy.groupQuantity - 1; i++)
		academy.groups[i] = old[i];
	strcpy(academy.groups[academy.groupQuantity - 1].name, name);
	academy.groups[academy.groupQuantity - 1].quantity = 0;
	academy.groups[academy.groupQuantity - 1].students = new Student[0];
	delete[] old;
}

void addStudent(Group &group, char *name, char *surname, int age)
{
	Student *old = group.students;
	group.quantity++;
	group.students = new Student[group.quantity];
	for (int i = 0; i < group.quantity - 1; i++)
		group.students[i] = old[i];
	strcpy(group.students[group.quantity - 1].name, name);
	strcpy(group.students[group.quantity - 1].surname, surname);
	group.students[group.quantity - 1].age = age;
	group.students[group.quantity - 1].averageGrade = 70 + rand() % 25 + (rand() % 100) / 100.0;
	delete[] old;
}

void addLecturer(Academy &academy, char *name, char *surname)
{
	Lecturer *old = academy.lecturers;
	academy.lectQuantity++;
	academy.lecturers = new Lecturer[academy.lectQuantity];
	for (int i = 0; i < academy.lectQuantity - 1; i++)
		academy.lecturers[i] = old[i];
	strcpy(academy.lecturers[academy.lectQuantity - 1].name, name);
	strcpy(academy.lecturers[academy.lectQuantity - 1].surname, surname);
	delete[] old;
}

void removeStudent(Group &group, int student)
{
	if (group.quantity < 1)
	{
		cout << "�������� �����������" << endl;
		return;
	}

	Student *old = group.students;
	group.quantity--;
	group.students = new Student[group.quantity];
	for (int i = 0; i < group.quantity; i++)
	{
		if (i < student)
			group.students[i] = old[i];
		else group.students[i] = old[i + 1];
	}
	delete[] old;
}

void removeLecturer(Academy &academy, int lecturer)
{
	if (academy.lectQuantity < 1)
	{
		cout << "������������� �����������" << endl;
		return;
	}

	Lecturer *old = academy.lecturers;
	academy.lectQuantity--;
	academy.lecturers = new Lecturer[academy.lectQuantity];
	for (int i = 0; i < academy.lectQuantity; i++)
	{
		if (i < lecturer)
			academy.lecturers[i] = old[i];
		else academy.lecturers[i] = old[i + 1];
	}
	delete[] old;
}

void removeGroup(Academy &academy, int group)
{
	if (academy.groupQuantity < 1)
	{
		cout << "������ �����������" << endl;
		return;
	}

	Group *old = academy.groups;
	academy.groupQuantity--;
	academy.groups = new Group[academy.groupQuantity];
	for (int i = 0; i < academy.groupQuantity; i++)
	{
		if (i < group)
			academy.groups[i] = old[i];
		else academy.groups[i] = old[i + 1];
	}
	delete[] old;
}

void transferStudent(Group &origin, Group &destination, int student)
{
	Student st = origin.students[student];
	addStudent(destination, st.name, st.surname, st.age);
	removeStudent(origin, student);
}

void sortStudents(Group &group, StudentSort type)
{
	Student tempSt;
	for (int i = 0; i < group.quantity; i++)
	{
		tempSt = group.students[i];

		int j;

		for (j = i - 1; j >= 0 && compStud(group.students[j], tempSt, type); j--)
		{
			group.students[j + 1] = group.students[j];
		}
		group.students[j + 1] = tempSt;
	}
}

bool compStud(Student arraySt, Student compSt, StudentSort type)
{
	if (type == byAge)
		return arraySt.age > compSt.age;

	else
		return 0 < strcmp(arraySt.surname, compSt.surname);
}

void mixStudents(Group &group)
{
	int k, l;
	Student temp;

	for (int i = 0; i < group.quantity; i++)
	{
		k = rand() % group.quantity;
		l = rand() % group.quantity;

		temp = group.students[k];
		group.students[k] = group.students[l];
		group.students[l] = temp;
	}
}

void sortGroups(Academy &academy, GroupSort type)
{
	Group tempGr;
	for (int i = 0; i < academy.groupQuantity; i++)
	{
		tempGr = academy.groups[i];

		int j;

		for (j = i - 1; j >= 0 && compGroup(academy.groups[j], tempGr, type); j--)
		{
			academy.groups[j + 1] = academy.groups[j];
		}
		academy.groups[j + 1] = tempGr;
	}
}

bool compGroup(Group arrayGr, Group compGr, GroupSort type)
{
	if (type == byQuantity)
	{
		return arrayGr.quantity > compGr.quantity;
	}

	else
	{
		return getAverage(arrayGr) > getAverage(compGr);
	}
}

float getAverage(Group group)
{
	float result = 0;
	for (int i = 0; i < group.quantity; i++)
		result += group.students[i].averageGrade;
	return result / (float)group.quantity;
}

void saveAcademy(Academy &academy)
{
	char *path = "database.txt";
	FILE *pf = fopen(path, "w");

	char * age = new char[50];
	char * averageGrade = new char[50];

	for (int i = 0; i < academy.groupQuantity; i++)
	{
		fputs("#GROUP\n", pf);
		fputs(academy.groups[i].name, pf);
		fputc('\n', pf);

		for (int s = 0; s < academy.groups[i].quantity; s++)
		{
			fputs(academy.groups[i].students[s].surname, pf);
			fputc(' ', pf);
			fputs(academy.groups[i].students[s].name, pf);
			fputc(' ', pf);
						
			sprintf(age, "%d", academy.groups[i].students[s].age);
			fputs(age, pf);
			fputc(' ', pf);
						
			sprintf(averageGrade, "%4.2f", academy.groups[i].students[s].averageGrade);
			fputs(averageGrade, pf);
			fputc('\n', pf);
		}
	}
	
	fputs("#LECTURERS\n", pf);
	for (int i = 0; i < academy.lectQuantity; i++)
	{
		fputs(academy.lecturers[i].surname, pf);
		fputc(' ', pf);
		fputs(academy.lecturers[i].name, pf);
		fputc('\n', pf);
	}
	
	delete[] age;
	delete[] averageGrade;
	fclose(pf);
}

void loadAcademy(Academy &academy)
{
	char *path = "database.txt";
	int res = _access(path, 0); //�������� �� �������������: 0 - ��, 1 - ���
	
	if (res == 0) //���� ���� ����������
	{
		academy.groupQuantity = 0;
		academy.lectQuantity = 0;
		
		FILE *pf = fopen(path, "r");

		char * buffer = new char[50];
		char * surname = new char[50];
		char * name = new char[50];
		char * age = new char[50];
		char * grade = new char[50];

		int type = 0;
		char keyGroup[] = "#GROUP";
		char keyLect[] = "#LECTURERS";

		/*
		TYPE
		General:
		0 - key (#___)
		1 - group name

		For students:
		2 - surname
		3 - name
		4 - age
		5 - grade

		For lecturers:
		6 - surname
		7 - name
		*/
		int counter = 0;
		while (!feof(pf))
		{
			char c = fgetc(pf);
			if (c == ' ')
			{
				type++;
				counter = 0;
			}
			else if (c == '#')
			{
				type = 0;
				buffer[counter++] = c;
				buffer[counter] = '\0';
			}
			else if (c == '\n' && type != 0) //���� ��� �� �������� �����
			{
				if (type == 1)
				{
					type++;
					addGroup(academy, buffer);
				}
					
				else if (type == 5)
				{
					type = 2;
					addStudent(academy.groups[academy.groupQuantity - 1], name, surname, atoi(age));
				}
				else if (type == 7)
				{
					type--;
					addLecturer(academy, name, surname);
				}
				counter = 0;
			}

			else if (type == 0)
			{
				buffer[counter++] = c;
				buffer[counter] = '\0';
			}
			else if (type == 1)	//group name
			{
				buffer[counter++] = c;
				buffer[counter] = '\0';
			}
			else if (type == 2 || type == 6) //student or professor surname
			{
				surname[counter++] = c;
				surname[counter] = '\0';
			}
			else if (type == 3 || type == 7) //student or professor name
			{
				name[counter++] = c;
				name[counter] = '\0';
			}
			else if (type == 4) //student age
			{
				age[counter++] = c;
				age[counter] = '\0';
			}
			else if (type == 5) //student grade
			{
				grade[counter++] = c;
				grade[counter] = '\0';
			}

			if (strcmp(keyGroup, buffer) == 0)
			{
				fgetc(pf);//��������� ������� �� ����� ������
				type = 1;
				counter = 0;
			}
			if (strcmp(keyLect, buffer) == 0)
			{
				buffer[0] = '\0'; //��� �� - ������ ���))
				fgetc(pf);//��������� ������� �� ����� ������
				type = 6;
				counter = 0;
			}
		}

		fclose(pf);
		delete[] buffer;
		delete[] surname;
		delete[] name;
		delete[] age;
		delete[] grade;
	}
	
	else
		initializeAcademy(academy);
}