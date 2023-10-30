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
	for (; a--; a > 0) 
	{
		betw *= x;
	}
	return(betw);
}
float getR(float p) 
{
	return(p / float(100));
}

void Number_1()
{
	double S, p, n, r, m;
	cout << "Введите займ (S) рублей: ";
	cin >> S;
	cout << "Введите (%) p: ";
	cin >> p;
	cout << "Введите на сколько лет (n): ";
	cin >> n;

	if (S <= p || p <= n || S <= n || S <= 0 || n <= 0)
	{
		cout << "Введите корректные значения для (S), (p) и (n) | -> (S > p > n)";
		return;
	}

	r = p / 100.0;

	if (n == 0)
	{
		cout << "(m) Месячная выплата равна: " << S / (12 * n);
	}
	else if (r == 0)
	{
		cout << "(m) Месячная выплата равна: " << S / (12 * n);
	}
	else
	{
		m = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
		cout << "(m) Месячная выплата равна: " << m;
	}
}

void Number_2()
{
	double S, m, n, eps;
	double p = 0;
	cout << "Величина ссуды (S): ";
	cin >> S;
	cout << "Месячная выплата (m): ";
	cin >> m;
	cout << "Количество лет (n): ";
	cin >> n;
	cout << "Погрешность результата (1e-8): ";
	cin >> eps;
	
	if ((m == 0) and (S == 0))
	{
		cout << "Вводимый (%) может быть любым, либо его нет";
		return;
	}
	
	else if ((m < 0) or (n <= 0) or (((m != 0) and (S == 0)) or ((m == 0) and (S != 0))))
	{
		cout << "Решение отсутствует, введите корректные значения (S), (m), (n) ";
		return;
	}

	double coef = 100;
	for (int i1 = coef * 100; i1 -= 1; i1 >= 0)
	{
		double m2 = S * getR(double(i1) / coef) * getPower(1 + getR(double(i1) / coef), n) / (12 * (getPower(1 + getR(double(i1) / coef), n) - 1));
		if (abs((m2)-m) < eps)
		{
			p = (double(i1) / coef);
		}
	} 

	cout << "P(%) под который выдана ссуда (S): " << p << endl;
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
	 Number_1();
	// Number_2();
	// Number_3();
	// Number_4();
	// Number_5();
}