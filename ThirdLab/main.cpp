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
	//getchar();
	return 0;

	//switch (c)
	//{
	//case 1: //Вручную
	//	cout << "Как много наследников вы хотите??" << endl;
	//	cout << "--> ";
	//	cin >> N;

	//	Parr** parr = new Parr * [N];

	//	while (exit_equ != 1 && N > 0)
	//	{
	//		cout << "C чем вы хотите работать" << endl;
	//		cout << "1 - Прямая" << endl;
	//		cout << "2 - Эллипс" << endl;
	//		cout << "3 - Гипербола" << endl;
	//		cout << "0 - Выход" << endl;
	//		cout << "--> ";
	//		cin >> c;

	//		if (c == 1)
	//		{
	//			system("cls");
	//			cout << "Введите коэфициенты для прямой через пробел (x, k, b): ";
	//			cin >> x_str >> k_str >> b_str;
	//			parr[i] = new Straight;
	//			Straight straight(x_str, k_str, b_str);
	//			parr[i] = &straight;
	//			cout << "Координата Y прямой: " << parr[i]->findY() << ", при введенных Х = " << x_str << ", К = " << k_str << ", В = " << b_str << endl;
	//			i++;
	//			N--;
	//		}

	//		if (c == 2)
	//		{
	//			system("cls");
	//			cout << "Введите коэфициенты для эллипса через пробел (x, а, b): ";
	//			cin >> x_ell >> a_ell >> b_ell;
	//			if (a_ell == 0)
	//			{
	//				cout << "Значение А для эллипса не может быть нулевым, поэтому А будет равен единице" << endl;
	//				a_ell = 1;
	//			}
	//			if (b_ell == 0)
	//			{
	//				cout << "Значение B для эллипса не может быть нулевым, поэтому B будет равен единице" << endl;
	//				b_ell = 1;
	//			}
	//			parr[i] = new Ellips;
	//			Ellips ellips(x_ell, a_ell, b_ell);
	//			parr[i] = &ellips;
	//			cout << "Координата Y эллипса: " << parr[i]->findY() << ", при введенных Х = " << x_ell << ", А = " << a_ell << ", В = " << b_ell << endl;
	//			i++;
	//			N--;
	//		}
	//		if (c == 3)
	//		{
	//			system("cls");
	//			cout << "Введите коэффициенты для гиперболы через пробел (x, k, b): ";
	//			cin >> x_hyp >> k_hyp >> b_hyp;
	//			if (x_hyp == 0)
	//			{
	//				cout << "Значение Х для гиперболы не может быть нулевым, поэтому Х будет равен единице" << endl;
	//				x_hyp = 1;
	//			}
	//			parr[i] = new Hyperbola;
	//			Hyperbola hyperbola(x_hyp, k_hyp, b_hyp);
	//			parr[i] = &hyperbola;
	//			cout << "Координата Y гиперболы: " << parr[i]->findY() << ", при введенных Х = " << x_hyp << ", К = " << k_hyp << ", В = " << b_hyp << endl;
	//		}
	//		if (c == 0)
	//		{
	//			exit_equ = 1;
	//		}
	//	}
	//	break;
	//case 2:
	//	system("cls");
	//	Parr** parr = new Parr*[1];
	//	int N = 1;
	//	inFile.open(stra);
	//	if (!inFile)
	//	{
	//		cout << "Ошибка открытия файла!" << endl;
	//		exit(1);
	//	}
	//	cout << "Для прямых: " << endl;
	//	while (!feof)
	//	{
	//		inFile >> x_str >> k_str >> b_str;
	//			Parr** parr = new Parr * [N];
	//			parr[N-1] = new Straight;
	//			Straight straight(x_str, k_str, b_str);
	//			parr[N-1] = &straight;
	//			cout << "Координата Y прямой: " << parr[N-1]->findY() << ", при введенных Х = " << x_str << ", К = " << k_str << ", В = " << b_str << endl;
	//			N++;
	//	}
	//	inFile.close();

	//	inFile.open(ell);
	//	if (!inFile)
	//	{
	//		cout << "Ошибка открытия файла!" << endl;
	//		exit(1);
	//	}
	//	cout << "Для эллипса: " << endl;
	//	while (!feof)
	//	{
	//		inFile >> x_ell >> a_ell >> b_ell;
	//		Parr** parr = new Parr * [N];

	//		if (a_ell == 0)
	//		{
	//			cout << "Значение А для эллипса не может быть нулевым, поэтому А будет равен единице" << endl;
	//			a_ell = 1;
	//		}
	//		if (b_ell == 0)
	//		{
	//			cout << "Значение B для эллипса не может быть нулевым, поэтому B будет равен единице" << endl;
	//			b_ell = 1;
	//		}
	//		parr[N-1] = new Ellips;
	//		Ellips ellips(x_ell, a_ell, b_ell);
	//		parr[N-1] = &ellips;
	//		cout << "Координата Y эллипса: " << parr[N-1]->findY() << ", при введенных Х = " << x_ell << ", А = " << a_ell << ", В = " << b_ell << endl;
	//		N++;
	//	}
	//	inFile.close();

	//	inFile.open(hyp);
	//	if (!inFile)
	//	{
	//		cout << "Ошибка открытия файла!" << endl;
	//		exit(1);
	//	}
	//	cout << "Для гипербол: " << endl;
	//	while (!feof)
	//	{
	//		inFile >> x_hyp >> k_hyp >> b_hyp;
	//		Parr** parr = new Parr * [N];
	//		if (x_hyp == 0)
	//		{
	//			cout << "Значение Х для гиперболы не может быть нулевым, поэтому Х будет равен единице" << endl;
	//			x_hyp = 1;
	//		}
	//		parr[N-1] = new Hyperbola;
	//		Hyperbola hyperbola(x_hyp, k_hyp, b_hyp);
	//		parr[N-1] = &hyperbola;
	//		cout << "Координата Y гиперболы: " << parr[N-1]->findY() << ", при введенных Х = " << x_hyp << ", К = " << k_hyp << ", В = " << b_hyp << endl;
	//		N++;
	//	}
	//	inFile.close();
	//		 
	//	
	//	cout << "Данные взяты!" << endl;
	//	inFile.close();
	//break;	case 0:
	//	exit(0);
	//	break;
	//default:
	//	break;
	//}



	

	return 0;
}

//int main() {
//
//	int N = 0;
//	Parr** parr = new Parr * [N];
//	//parr[0] = new Straight(1, 1, 1);
//	//cout << "Parr[0]>>" << parr[0]->findY() << endl;
//
//
//	//int i;
//	//i = parr[0]->write();
//	//Parr** buff = new Parr * [2];
//	//Straight str2(parr[0]);
//	//buff[0] = &str2;
//	//delete[] parr;
//	//Parr** parr = new Parr * [2];
//	//parr = buff;
//	//delete[] buff;
//	//Straight str2;
//	//str.read();
//	//parr[1] = &str2;
//
//	readFile(parr, N);
//	AddNew_ffile(parr, N, 3);
//	for (int i = 0; i < N;i++)
//	{
//		//AddNew(parr, N, 1);
//		cout << "Parr[" << (i+1) << "] >> " << parr[i]->findY() << endl;
//	}
//	writeFile(parr, N);
//
//	/*for (int i = 0; i < N; i++)
//	{
//		parr[i]->write();
//	}
//	Straight::down();*/
//
//
//
//
//	/*AddNew(parr);
//	cout << "Parr[">>N-1"] >> " << parr[N-1]->findY() << endl;
//	parr[1]->write();*/
//
//}

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