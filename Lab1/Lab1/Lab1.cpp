// Lab1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

struct info
{
	char name[80];
	int subjects_marks[5];
	bool whois;
	double average;
}; struct info students[80];

int n = 0;

void reading_file()
{
	setlocale(LC_ALL, "RUS");
	string s;
	ifstream reading;
	reading.open("students (1).csv");
	//открытие и чтение файла
	if (reading.is_open())
	{
		cout << "Weiting we try to read it...\n";
		Sleep(1000);
		while (getline(reading, s)) 
		{ // пока не достигнут конец файла класть очередную строку в переменную (s)
			SetConsoleCP(1251); //настройка чтения русских букв 
			SetConsoleOutputCP(1251); //вывод русских букв
			cout << s << endl; // выводим на экран students.txt
		}
	}
	else cout << "Unable to open file"; //выводит на экран проблему с открытием файла
	reading.close(); 
}

void copy_file()
{
	setlocale(LC_ALL, "RUS");
	ifstream fin;
	fin.open("students (1).csv");
	ofstream fout;
	fout.open("rating.txt");
	char ch;
	// копирование данных из students.txt в rating.txt
	while (!fin.eof())
	{
		SetConsoleCP(1251); //настройка чтения русских букв 
		SetConsoleOutputCP(1251); //вывод русских букв
		fin.get(ch);
		fout << ch;
	}
	fin.close();
}

void working_file()
{
	ifstream working;
	//working.open("students (1).csv", ios_base::in);
	working.open("students.txt", ios_base::in);
	string str;
	char temp[100];
	char num1[100];
	int num2[100];
	int num3[100];
	int i, j; int fnum; 
	if (working.is_open())
	{
		do
		{
			// пробуем считать число
	//		if (working >> students[k].subjects_marks)
			//TODO: remove
			
			getline(working,str);
			n = atoi(str.c_str());
			//считываем числа до каждой запятой и вносим в массив
			for (i = 0; i < n; i++)
			{
				getline(working, str);
				for (j = 0; str.c_str()[j] != ','; j++)
				{
					temp[j] = str.c_str()[j];
				}
				temp[j] = '\0';
				strcpy_s(students[i].name, temp);
				int jtemp = 0;
				for (j++; str.c_str()[j] != ','; j++)
				{
					temp[jtemp] = str.c_str()[j];
					jtemp++;
				}
				temp[jtemp] = '\0';
				students[i].subjects_marks[0] = atoi(temp);
				//////////////////////////////////////////////
				jtemp = 0;
				for (j++; str.c_str()[j] != ','; j++)
				{
					temp[jtemp] = str.c_str()[j];
					jtemp++;
				}
				temp[jtemp] = '\0';
				students[i].subjects_marks[1] = atoi(temp);

				jtemp = 0;
				for (j++; str.c_str()[j] != ','; j++)
				{
					temp[jtemp] = str.c_str()[j];
					jtemp++;
				}
				temp[jtemp] = '\0';
				students[i].subjects_marks[2] = atoi(temp);

				jtemp = 0;
				for (j++; str.c_str()[j] != ','; j++)
				{
					temp[jtemp] = str.c_str()[j];
					jtemp++;
				}
				temp[jtemp] = '\0';
				students[i].subjects_marks[3] = atoi(temp);

				jtemp = 0;
				for (j++; str.c_str()[j] != ','; j++)
				{
					temp[jtemp] = str.c_str()[j];
					jtemp++;
				}
				temp[jtemp] = '\0';
				students[i].subjects_marks[4] = atoi(temp);

				students[i].whois = (str.c_str()[j + 1] == 'T');
				
				
			}
		}
		 while (!working.eof());

	}
	else EXIT_FAILURE;
	working.close();
}

void average()
{
	ofstream www;
	www.open("ratings.txt",fstream::out);
	//info nullstudent = { "0",{0,0,0,0,0},false,0.0 };
	int i, j, count = 0;
	int counter = 0;
	int max = 60;
	info *studentss;
	info temp;
	if (www.is_open())
	{
		for (i = 0; i < n; i++)
		{
			if (students[i].whois)
			{
				counter++;
			}
		}
		studentss = new info[counter];

		//for (int i = 0; i < counter; i++)
		//{
		//	studentss[i] = nullstudent;
		//}

		//средний балл бюджетника
		for (i = 0; i < n; i++)
		{
			for (j = 0; j <= 4; j++)
			{
				count += students[i].subjects_marks[j];
			}
			students[i].average = count / 5.0;
			count = 0;
		}

		for (j = 0; j < n; j++)
		{
			cout << students[j].name << " " << students[j].average << " " << endl;;
		}
		cout << "////////////////////////////////////////////////////////////////////////////////////////\n";
		cout << "////////////////////////////////////////////////////////////////////////////////////////";
		cout << endl;
		j = 0;
		//нахождение студентов-бюджетников
		for (i = 0; i < n; i++)
		{
			if (students[i].whois)
			{
				studentss[j] = students[i];
				j++;
				//studentss[i] = students[i];
				//memcpy(&studentss[i].average, &students[i].average, sizeof(studentss));
				//cout << studentss[i].average << " " << endl;
			}

		}
		/*	for (int i = 0; i < counter; i++)
			{
				cout << studentss[i].name << endl;
			}
			*/
		//сортировка по убыванию студентов(баллов)
		for (j = 0; j < counter; j++)
		{
			for (int i = 0; i < counter - 1; i++)
			{
				if (studentss[i].average < studentss[i + 1].average)
				{
					temp = studentss[i];
					studentss[i] = studentss[i + 1];
					studentss[i + 1] = temp;

					//swap(&studentss[i], &studentss[i + 1]);
				}

			}
		}

		int scounter = 0;
		scounter = (0.4*counter);//подсчет тех 40% бюджетников

		double stependiaa = 0;
		double stependia = 0;
		//нахождение степендии
		for (i = 0; i < scounter; i++)
		{
			stependiaa += studentss[i].average;
			stependia = stependiaa / scounter;
		}

		cout << "Name \t" << setw(2) << "        Mark \t\n";
		cout << endl;
		for (i = 0; i < scounter; i++)
		{
			cout << studentss[i].name << " \t" << setw(2) << studentss[i].average << " \t" << endl;
		}
		cout << "/////////////////////////////////////////////////////////////////////\n";
		cout << "/////////////////////////////////////////////////////////////////////\n";
		cout << "Name \t" << setw(2) << "        Mark \t\n";
		cout << endl;
		for (i = 0; i < scounter; i++)
		{
			if (studentss[i].average >= stependia)
			{
				cout << studentss[i].name << " \t" << setw(2) << studentss[i].average << " \t" << endl;
			}
		}

	}
	else EXIT_FAILURE;
	www.close();
}

int main()
{
	setlocale(0, "rus");
	//reading_file();
	//copy_file();
	working_file();
	average();
	system("pause");
    return 0;
}

