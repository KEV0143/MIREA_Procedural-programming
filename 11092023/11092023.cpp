#include <iostream>
#include <Windows.h>
#include <cmath>
#include <math.h>
using namespace std;

void Number_1()
{
    double R, r, h, V, S, l;
    const double PI = 3.14;

    cout << "[ Number 1 ]" << endl;
    cout << "Введите значения R, r и h для усечённого конуса" << endl;

    cout << "Введите радиус большего основания [ R ]: ";
    cin >> R;
    cout << "Введите радиус меньшего основания [ r ]: ";
    cin >> r;
    cout << "Введите высоту [ h ]: ";
    cin >> h;

    if (R <= 0 or r <= 0 or h <= 0)
    {
        cout << "Введите корректное значение! Радиусы и высота должны быть положительными числами." << endl;
    }
    else
    {
        l = sqrt(pow(R - r, 2) + pow(h, 2));
        S = PI * (pow(R, 2) + (R + r) * l + pow(r, 2));
        V = 0.33333333 * PI * h * (pow(R, 2) + R * r + pow(r, 2));
    }

    cout << "Образующай конуса l = " << l << endl;
    cout << "Площадь конуса S = " << S << endl;
    cout << "Объём конуса V = " << V << endl;
}

void Number_2()
{
    double x, a, w;
    cout << "[ Number 2 ]" << endl;

    cout << "Введите значения [ x ]: ";
    cin >> x;

    cout << "Введите значения [ a ]: ";
    cin >> a;

    if (x == 0)
    {
        cout << "X не может быть == 0" << endl;
    }

    else if (abs(x) < 1)
    {
        w = a * log(abs(x));
        cout << w << endl;
    }

    else if ((a - pow(x, 2)) < 0)
    {
        cout << "Нельзя извлечь корень из отрицательного числа" << endl;
    }

    else
    {
        w = sqrt(a - pow(x, 2));
        cout << w << endl;
    }
}

void Number_3()
{
    double x, y, b, z;
    cout << "[ Number 3 ]" << endl;

    cout << "Введите x = ";
    cin >> x;
    cout << "Введите y = ";
    cin >> y;
    cout << "Введите b = ";
    cin >> b;

    if (b - y <= 0 or b - x < 0 or b - y < 0)
    {
        cout << "Коэффициент log() не может быть меньше или равен 0";
    }

    else
    {
        z = log(b - y) * sqrt(b - x);
        cout << "z = " << z;
    }
}

void Number_4()
{
    float n, i;
    float y;
    cout << "[ Number 4 ]" << endl;

    
    cout << "Введите производное число N: ";
    cin >> n;
    y = floor (n);
    
    if (n > y)
    {
        y++;
    }

    if (n <= 0)
    {
        y = 1;
    }

        for (i = y; i < (y+10); i++)
        {
            cout << i << endl;
        }   
}

void Number_5()
{
    float x, y;
    cout << "[ Number 5 ]" << endl;

    for (x = -4; x <= 4; x += 0.5)
    {
        y = (x * x - 2 * x + 2) / (x - 1);

        if (x - 1 == 0)
        {
            cout << "x (" << x << ")    |     y = " << "Нельзя делать деление на нуль!" << endl;
        }
    else 
        {
            cout << "x (" << x << ")    |     y = " << y << endl;
        }
    }
}


int main()
{
    setlocale(0, "Russian");
  // Number_1();
  // Number_2();
    //Number_3();
    Number_4();
    //Number_5();
}