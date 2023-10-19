#include <iostream>
#include <Windows.h>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <string.h>
#include <string>
using namespace std;

float getPower(double x, double a)
{
	double betw = 1;
	for (; a--; a > 0) {
		betw *= x;
	}
	return(betw);
}
float getR(float p) {
	return(p / float(100));
}

void Number_1()
{
	double S;
	double p;
	double n;
	double r;
	double m;
	cout << "[ Number 1 ]" << endl;

	cout << "Введите значение S = ";
	cin >> S;
	cout << "Введите значение p = ";
	cin >> p;
	cout << "Введите значение n = ";
	cin >> n;

	if (S <= 0)
	{
		cout << "Числа не могут быть меньше нуля! \n";
	}

	else if (p == 0)
	{
		m = S / (12 * n);
	}

	else
	{
		r = p / 100;
		m = S * r * pow(1 + r, n) / (12 * (pow(1 + r, n) - 1));
	}

	if (12 * (pow(1 + r, n) - 1) == 0)
	{
		cout << "Нельзя разделить на 0! \n";
	}

	cout << "m = " << m << endl;
}

void Number_2()
{
	double S, m, n, eps;
	cout << "Введите ссуду: ";
	cin >> S;
	cout << "Введите месячную выплату: ";
	cin >> m;
	cout << "Введите количество лет: ";
	cin >> n;
	cout << "Введите погрешность: ";
	cin >> eps;
	if ((m == 0) and (S == 0))
	{
		cout << "Процент может быть любым, либо его нет";
		return;
	}
	else if ((m < 0) or (n <= 0) or (((m != 0) and (S == 0)) or ((m == 0) and (S != 0))))
	{
		cout << "Решений нет";
		return;
	}

	double coef = 100;
	for (int i1 = coef * 100; i1 -= 1; i1 >= 0)
	{
		double m2 = S * getR(double(i1) / coef) * getPower(1 + getR(double(i1) / coef), n) / (12 * (getPower(1 + getR(double(i1) / coef), n) - 1));
		if (abs((m2)-m) < eps)
		{
			cout << double(i1) / coef << endl;
		}
	}
}


void Number_3()
{
	ofstream file("Number_3.txt");
	if (file.is_open())
	{
		string text;
		cout << "Введите текст: ";
		getline(cin, text);
		file << text;
		file.close();
	}

	ifstream fin("Number_3.txt");
	if (fin.is_open())
	{
		string line;
		while (getline(fin, line))
		{
			cout << line << endl;
		}
		fin.close();
	}
}

void Number_4()
{
	ofstream file("Number_4.txt");
	if (file.is_open())
	{
		string text;
		cout << "Введите текст: ";
		getline(cin, text);
		file << text;
		file.close();
	}

	ifstream fin("Number_4.txt");
	if (fin.is_open())
	{
		string line;
		char ch;
		while (fin.get(ch))
		{
			if (ch >= '0' && ch <= '9')
			{
				cout << ch;
			}
		}
		fin.close();
	}
}

void Number_5()
{
	string x;
	int i = 0;
	getline(cin, x);


	for (int i = 0; i < x.length() - 1; i++)
	{
		for (int j = i; j < x.length() - 1; j++)
		{
			if (x[i] > x[j + 1])
			{
				swap(x[i], x[j + 1]);
			}
		}
	}
	cout << x.substr(count(x.begin(), x.end(), ' '), x.length()) << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	// Number_1();
	Number_2();
	// Number_3();
	// Number_4();
	// Number_5();
}