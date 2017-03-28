#include <fstream>
#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

int n; //ʳ������ ������ �����
int m; //ʳ������ ����� �����
int vertexes[2][20];
int inc_matr[20][20];
int sum_matr[20][20];

void input(int[][20]); //���������� �����
void output(int[][20]); //��������� �����
void inc(int[][20], int[][20], bool); //��������� ������� ������������
void sum(int[][20], int[][20], bool); //��������� ������� ��������

int main()
{
	setlocale(0, "russian");
	input(vertexes);

	cout << "��������� ����:\n";
	output(vertexes);

	cout << "����i�� ��� �����(0 - ����i���������, 1 - ��i���������):";
	bool type;
	cin >> type;

	cout << "\n������� i�����������i:\n";
	inc(vertexes, inc_matr, type);

	cout << "\n������� ���i�����i:\n";
	sum(vertexes, sum_matr, type);


	getch();
	system("pause");
}

void input(int A[][20]) //���������� �����
{
	ifstream fin("Lab1.txt");
	char vertex[5];

	fin >> vertex;
	n = atoi(vertex);//�������
	fin >> vertex;
	m = atoi(vertex);//�����

	for (int i = 0; i<m; i++)
		for (int j = 0; j<2; j++) {
			fin >> vertex;
			A[j][i] = atoi(vertex);
		}
	fin.close();
}

void output(int A[][20]) //��������� �����
{
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<2; j++)
			cout << A[j][i] << " ";
		cout << endl;
	}
}

void inc(int A[][20], int X[][20], bool g_type) //��������� ������� ������������
{
	// ��������� �������
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

	// ��������� �������
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

void sum(int A[][20], int X[][20], bool g_type) //��������� ������� ��������
{
	//���������� ������� �������� ������
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			X[i][j] = 0;
	
	//���������� �������
	for (int i = 0; i < m; i++)
	{
		X[A[0][i] - 1][A[1][i] - 1] = 1;
		if(!g_type)
			X[A[1][i] - 1][A[0][i] - 1] = 1;
	}

	//��������� �������
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