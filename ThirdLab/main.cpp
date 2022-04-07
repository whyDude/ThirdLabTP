#include <iostream>
#include <cmath>
#include <locale>
#include <string>
#include "Parr.h"
#include "Straight.h"
#include "Ellips.h"
#include "Hyperbola.h"

using namespace std;

/*������� 3 - ������� ����������� ����� "������" ��� ���������� ���������� � ��� ��������� �.
������� ����������� ������ "������", "������", "���������" �� ������ ��������� ���������� � � ����������� �� �������� ��������� �*/



int main()
{
	setlocale(LC_ALL, "Rus");

	int c, countY = 0, exit_equ = 0, i = 0, N;

	float x_ell, a_ell, b_ell; //ellips
	float x_str, k_str, b_str; //straight

	float x_hyp, k_hyp, b_hyp; //hyperbola

	cout << "��� ����� ����������� �� ������??" << endl;
	cout << "--> ";
	cin >> N;

	Parr** parr = new Parr * [N];

	while (exit_equ != 1 && N > 0)
	{
		cout << "C ��� �� ������ ��������" << endl;
		cout << "1 - ������" << endl;
		cout << "2 - ������" << endl;
		cout << "3 - ���������" << endl;
		cout << "0 - �����" << endl;
		cout << "--> ";
		cin >> c;

		if (c == 1)
		{
			system("cls");
			cout << "������� ����������� ��� ������ ����� ������ (x, k, b): ";
			cin >> x_str >> k_str >> b_str;
			parr[i] = new Straight;
			Straight straight(x_str, k_str, b_str);
			parr[i] = &straight;
			cout << "���������� Y ������: " << parr[i]->findY() << ", ��� ��������� � = " << x_str << ", � = " << k_str << ", � = " << b_str << endl;
			i++;
			N--;
		}

		if (c == 2)
		{
			system("cls");
			cout << "������� ����������� ��� ������� ����� ������ (x, �, b): ";
					cin >> x_ell >> a_ell >> b_ell;
					if (a_ell == 0)
					{
						cout << "�������� � ��� ������� �� ����� ���� �������, ������� � ����� ����� �������" << endl;
						a_ell = 1;
					}
					if (b_ell == 0)
					{
						cout << "�������� B ��� ������� �� ����� ���� �������, ������� B ����� ����� �������" << endl;
						b_ell = 1;
					}
			parr[i] = new Ellips;
			Ellips ellips(x_ell, a_ell, b_ell);
			parr[i] = &ellips;
			cout << "���������� Y �������: " << parr[i]->findY() << ", ��� ��������� � = " << x_ell << ", � = " << a_ell << ", � = " << b_ell << endl;
			i++;
			N--;
		}
		if (c == 3)
		{
			system("cls");
			cout << "������� ������������ ��� ��������� ����� ������ (x, k, b): ";
			cin >> x_hyp >> k_hyp >> b_hyp;
			if (x_hyp == 0)
			{
				cout << "�������� � ��� ��������� �� ����� ���� �������, ������� � ����� ����� �������" << endl;
				x_hyp = 1;
			}
			parr[i] = new Hyperbola;
			Hyperbola hyperbola(x_hyp, k_hyp, b_hyp);
			parr[i] = &hyperbola;
			cout << "���������� Y ���������: " << parr[i]->findY() << ", ��� ��������� � = " << x_hyp << ", � = " << k_hyp << ", � = " << b_hyp << endl;
		}
		if (c == 0)
		{
			exit_equ = 1;
		}
	}

	return 0;
}