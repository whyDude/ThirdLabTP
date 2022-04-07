#include <iostream>
#include <cmath>
#include <locale>
#include <string>
#include "Parr.h"
#include "Straight.h"
#include "Ellips.h"
#include "Hyperbola.h"

using namespace std;

/*Вариант 3 - Создать абстрактный класс "Кривые" для вычисления координаты у для некоторой х.
Создать производные классы "Прямая", "Эллипс", "Гипербола" со своими функциями вычисления у в зависимости от входного параметра х*/



int main()
{
	setlocale(LC_ALL, "Rus");

	int c, countY = 0, exit_equ = 0, i = 0, N;

	float x_ell, a_ell, b_ell; //ellips
	float x_str, k_str, b_str; //straight

	float x_hyp, k_hyp, b_hyp; //hyperbola

	cout << "Как много наследников вы хотите??" << endl;
	cout << "--> ";
	cin >> N;

	Parr** parr = new Parr * [N];

	while (exit_equ != 1 && N > 0)
	{
		cout << "C чем вы хотите работать" << endl;
		cout << "1 - Прямая" << endl;
		cout << "2 - Эллипс" << endl;
		cout << "3 - Гипербола" << endl;
		cout << "0 - Выход" << endl;
		cout << "--> ";
		cin >> c;

		if (c == 1)
		{
			system("cls");
			cout << "Введите коэфициенты для прямой через пробел (x, k, b): ";
			cin >> x_str >> k_str >> b_str;
			parr[i] = new Straight;
			Straight straight(x_str, k_str, b_str);
			parr[i] = &straight;
			cout << "Координата Y прямой: " << parr[i]->findY() << ", при введенных Х = " << x_str << ", К = " << k_str << ", В = " << b_str << endl;
			i++;
			N--;
		}

		if (c == 2)
		{
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
			parr[i] = new Ellips;
			Ellips ellips(x_ell, a_ell, b_ell);
			parr[i] = &ellips;
			cout << "Координата Y эллипса: " << parr[i]->findY() << ", при введенных Х = " << x_ell << ", А = " << a_ell << ", В = " << b_ell << endl;
			i++;
			N--;
		}
		if (c == 3)
		{
			system("cls");
			cout << "Введите коэффициенты для гиперболы через пробел (x, k, b): ";
			cin >> x_hyp >> k_hyp >> b_hyp;
			if (x_hyp == 0)
			{
				cout << "Значение Х для гиперболы не может быть нулевым, поэтому Х будет равен единице" << endl;
				x_hyp = 1;
			}
			parr[i] = new Hyperbola;
			Hyperbola hyperbola(x_hyp, k_hyp, b_hyp);
			parr[i] = &hyperbola;
			cout << "Координата Y гиперболы: " << parr[i]->findY() << ", при введенных Х = " << x_hyp << ", К = " << k_hyp << ", В = " << b_hyp << endl;
		}
		if (c == 0)
		{
			exit_equ = 1;
		}
	}

	return 0;
}