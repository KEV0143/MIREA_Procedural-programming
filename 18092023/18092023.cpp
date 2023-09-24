#include <iostream>
#include <Windows.h>
#include <iostream>
#include <cmath>
#include <algorithm>
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

void Number_2()
{
    double S; // начальная ссуда
    int n; // в течении n лет
    double mY; // месячная выплата
    double m = 0; // заданная под условие с выплатами r
    double r;
    double rTemp = 0.0000; // временное r для вычисления

    cout << "[ Number 2 ]" << endl;
    cout << "Введите начальную ссуду S = ";
    cin >> S;
    cout << "Введите сколько на сколько лет, n = ";
    cin >> n;
    cout << "Введите месячную выплату mY = ";
    cin >> mY;

    if (n == 0 || S <= 0) 
    { 
        cout << "Неверные годы или сумма кредита! \n";
    }

    while (m < mY) 
    { 
        r = rTemp;
        m = S * r * pow(1 + r, n) / (12 * (pow(1 + r, n) - 1));
    }

    cout << "p = " << r * 100 << "%" << endl;
}





int main()
{
    setlocale(0, "Russian");
    //Number_1();
    Number_2();
}