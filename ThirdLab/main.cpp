#include <iostream>
#include <cmath>
#include <locale>
#include <string>
#include "Parr.h"
#include "Straight.h"
#include "Ellips.h"
#include "Hyperbola.h"
#include <fstream>
using namespace std;

/*Вариант 3 - Создать абстрактный класс "Кривые" для вычисления координаты у для некоторой х.
Создать производные классы "Прямая", "Эллипс", "Гипербола" со своими функциями вычисления у в зависимости от входного параметра х*/

void readFile(Parr**& arr, int& N);
void AddNew_ffile(Parr**& arr, int& N, char id = 0);
void AddNew(Parr**& arr, int& N, char id);
void printArr(Parr**& arr, int &N);
void writeFile(Parr**& arr, int& N);
int Straight::count = 0;

int main()
{
	setlocale(LC_ALL, "Rus");

	int c, exit_equ = 0;
	int N = 0;
	Parr** parr = new Parr * [N];




	cout << "Вас приветствует программа 3-ей лабораторной по ТП!" << endl;
	cout << "Хотите ли вы хотите ввести данные из файла?" << endl;
	cout << "1 - Да" << endl;
	cout << "Any key - Нет" << endl;
	cout << "--> ";
	cin >> c;
	system("cls");
	if (c == 1) 
	{
		readFile(parr, N);
		if (N == 0)
		{
			cout << "Файл пуст" << endl;
		}
	}
	printArr(parr, N);
	while (exit_equ != 1)
	{
		cout << endl;
		cout << "Что вы хотите добавить" << endl;
		cout << "1 - Прямую" << endl;
		cout << "2 - Эллипс" << endl;
		cout << "3 - Гиперболу" << endl;
		cout << "0 - Выход" << endl;
		cout << "--> ";
		cin >> c;
		switch (c)
		{
		case 1:
			AddNew(parr, N, 1);
			break;
		case 2:
			AddNew(parr, N, 2);
			break;
		case 3:
			AddNew(parr, N, 3);
			break;
		case 0:
			exit_equ = 1;
			break;
		}
		printArr(parr, N);
	}
	cout << endl;
	cout << "Хотите ли вы хотите внести данные в файл?" << endl;
	cout << "1 - Да" << endl;
	cout << "Any key - Нет" << endl;
	cout << "--> ";
	cin >> c;
	if (c == 1)
	{
		writeFile(parr, N);
	}
	getchar();
	return 0;
}


void AddNew_ffile(Parr**& arr, int& N, char id)
{
	Parr** newarr =new Parr * [N+1];
	for (int i = 0;i < N;i++)
		newarr[i] = arr[i];
	switch (id)
	{
	case 1:
		newarr[N] = new Straight(N, N, N );
		break;
	case 2:
		newarr[N] = new Ellips(N, N, N);
		break;
	case 3:
		newarr[N] = new Hyperbola(N, N, N);
		break;
	}
	
	N++;
	
	delete [] arr;
	arr = newarr;
}

void readFile(Parr**& arr, int& N)
{
	int n, id;
	ifstream inFile;
	string stra = "C:\\Flesh\\SUAI_works\\TO\\ThirdLab\\ThirdLab\\ThirdLab\\straight.txt";
	inFile.open(stra, ios_base::in);
	if (!inFile.is_open())
	{
		cout << "Error" << endl;
		return;
	}
	inFile >> n;
	for (int i=0; i < n;i++) {
		inFile >> id;
		AddNew_ffile(arr, N, id);
		arr[N-1]->read(inFile);
	}
	inFile.close();
	
}

void writeFile(Parr**& arr, int& N) {
	ofstream outFile;
	string stra = "C:\\Flesh\\SUAI_works\\TO\\ThirdLab\\ThirdLab\\ThirdLab\\straight.txt";
	outFile.open(stra, ios_base::out);
	if (!outFile.is_open())
	{
		cout << "Error" << endl;
		return;
	}
	outFile << Straight::getCount() << "\n";
	for (int i = 0; i < N;i++){
		arr[i]->write(outFile);
	}
	outFile.close();

}

void AddNew(Parr**& arr, int& N, char id)
{
	Parr** newarr = new Parr * [N + 1];
	for (int i = 0;i < N;i++)
		newarr[i] = arr[i];
	switch (id)
	{
	case 1:
		float x_str, k_str, b_str; //straight
		system("cls");
		cout << "Введите коэфициенты для прямой через пробел (x, k, b): ";
		cin >> x_str >> k_str >> b_str;
		newarr[N] = new Straight(x_str, k_str, b_str);\
		break;
	case 2:
		float x_ell, a_ell, b_ell; //ellips
		system("cls");
		cout << "Введите коэфициенты для эллипса через пробел (x, а, b): ";
		cin >> x_ell >> a_ell >> b_ell;
		if (a_ell == 0)
		{
			cout << "Значение А для эллипса не может быть нулевым, поэтому А будет равен единице" << endl;
			a_ell = 1;
		}
		if (b_ell == 0)
		{
			cout << "Значение B для эллипса не может быть нулевым, поэтому B будет равен единице" << endl;
			b_ell = 1;
		}
		newarr[N] = new Ellips(x_ell, a_ell, b_ell);
		break;
	case 3:
		float x_hyp, k_hyp, b_hyp; //hyperbola
		system("cls");
		cout << "Введите коэффициенты для гиперболы через пробел (x, k, b): ";
		cin >> x_hyp >> k_hyp >> b_hyp;
		if (x_hyp == 0)
		{
		cout << "Значение Х для гиперболы не может быть нулевым, поэтому Х будет равен единице" << endl;
		x_hyp = 1;
		}
		newarr[N] = new Hyperbola(x_hyp, k_hyp, b_hyp);
		break;
	}
	newarr[N]->print();
	N++;

	delete[] arr;
	arr = newarr;
}

void printArr(Parr**& arr, int& N)
{
	for (int i = 0; i < N;i++)
	{
		cout << "Array el >> " << i + 1 << " << ";
		arr[i]->print();
	}
}