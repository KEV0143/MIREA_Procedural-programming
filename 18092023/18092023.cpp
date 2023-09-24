#include <iostream>
#include <Windows.h>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <string.h>
#include <string>
using namespace std;

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


    for (int i = 0; i < x.length() - 1; i++) {
        for (int j = i; j < x.length() - 1; j++) {
            if (x[i] > x[j + 1]) {
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
   // Number_2();
   // Number_3();
   // Number_4();
    Number_5();
}