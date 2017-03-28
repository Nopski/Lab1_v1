#include <fstream>
#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

int n; //Кількість вершин графу
int m; //Кількість ребер графу
int vertexes[2][20];
int inc_matr[20][20];
int sum_matr[20][20];

void input(int[][20]); //Считування графу
void output(int[][20]); //Виведення графу
void inc(int[][20], int[][20], bool); //Виведення матриці інцидентності
void sum(int[][20], int[][20], bool); //Виведення матриці суміжності

int main()
{
	setlocale(0, "russian");
	input(vertexes);

	cout << "Введенний граф:\n";
	output(vertexes);

	cout << "Введiть тип графу(0 - Неорiєнтований, 1 - Орiєнтований):";
	bool type;
	cin >> type;

	cout << "\nМатриця iнцидентностi:\n";
	inc(vertexes, inc_matr, type);

	cout << "\nМатриця сумiжностi:\n";
	sum(vertexes, sum_matr, type);


	getch();
	system("pause");
}

void input(int A[][20]) //Считування графу
{
	ifstream fin("Lab1.txt");
	char vertex[5];

	fin >> vertex;
	n = atoi(vertex);//Вершини
	fin >> vertex;
	m = atoi(vertex);//Ребра

	for (int i = 0; i<m; i++)
		for (int j = 0; j<2; j++) {
			fin >> vertex;
			A[j][i] = atoi(vertex);
		}
	fin.close();
}

void output(int A[][20]) //Виведення графу
{
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<2; j++)
			cout << A[j][i] << " ";
		cout << endl;
	}
}

void inc(int A[][20], int X[][20], bool g_type) //Виведення матриці інцидентності
{
	// Створення матриці
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j++)
			if (g_type)
			{
				if (A[0][j] == i && A[1][j] == i)
					X[i - 1][j] = 2;
				else if (A[0][j] == i)
					X[i - 1][j] = -1;
				else if (A[1][j] == i)
					X[i - 1][j] = 1;
				else
					X[i - 1][j] = 0;
			}
			else
			{
				if (A[0][j] == i && A[1][j] == i)
					X[i - 1][j] = 2;
				else if (A[0][j] == i || A[1][j] == i)
					X[i - 1][j] = 1;
				else
					X[i - 1][j] = 0;
			}

	// Виведення матриці
	for (int i = 0; i <= n; i++)
	{
		if (i == 0)
			for(int k=0; k<=m; k++)
				if(k==0)
					printf(" ");
				else
					printf(" e%d", k);
		else
		{
			printf("%d", i);
			for (int j = 0; j < m; j++)
				printf("%3d", X[i - 1][j]);
		}
		cout << endl;
	}
}

void sum(int A[][20], int X[][20], bool g_type) //Виведення матриці суміжності
{
	//Заповнення матриці суміжності нулями
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			X[i][j] = 0;
	
	//Заповнення матриці
	for (int i = 0; i < m; i++)
	{
		X[A[0][i] - 1][A[1][i] - 1] = 1;
		if(!g_type)
			X[A[1][i] - 1][A[0][i] - 1] = 1;
	}

	//Виведення матриці
	for (int i = 0; i <= n; i++)
	{
		if (i != 0)
			printf("%d", i);
		for (int j = 0; j <= n; j++)
		{
			if (i == 0)
			{
				if (j == 0)
					printf(" ");
				else
					printf("%2d", j);
			}
			else if (j != 0)
			{
				printf("%2d", X[i - 1][j - 1]);
			}
		}
		cout << endl;
	}
}