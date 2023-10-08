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
float getPower(double x, double a) {
    double betw = 1;
    for (; a--; a > 0) {
        betw *= x;
    }
    return(betw);
}
float getR(float p) {
    return(p / float(100));
}

    cout << m << " - месячная выплата";
} {
    double S, m, n;
    cout << "Введите величину ссуды" << endl;
    cin >> S;
    cout << "Введите месячную выплату" << endl;
    cin >> m;
    cout << "Введите количество лет" << endl;
    cin >> n;
    if ((m == 0) and (S == 0)) {
        cout << "процент может быть любым, т.к. выплаты всегда 0 (либо их нет)";
        return;
    }
    else if ((m < 0) or (n <= 0) or (((m != 0) and (S == 0)) or ((m == 0) and (S != 0)))) {
        cout << "Решений нет";
        return;
    }
    int countOfDecisions = 0;
    double lastDecision = 0;
    double range = 0;
    double coef = 10;
    while (true) {
        for (int i1 = coef * 1000; i1 -= 1; i1 > 0) {
            //cout << i1 << endl;
            double m2 = S * getR(double(i1) / coef) * getPower(1 + getR(double(i1) / coef), n) / (12 * (getPower(1 + getR(double(i1) / coef), n) - 1));
            //cout << m2 << endl;
            if (abs((m2)-m) < range) {
                lastDecision = double(i1) / coef;
                countOfDecisions++; //cout << "ссуда выдана под " << i1 << "%";
            }
        }
        if (countOfDecisions == 1) {
            if (lastDecision <= (1 / coef + 1e-8)) { cout << "Так нельзя"; return; }
            cout << "ссуда выдана под " << lastDecision << "%";
            return;
        }
        else if (countOfDecisions > 1) { cout << range << "Ошибка"; return; }
        else {
            range += 0.001;
        }
    }
    cout << "END";
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
  Number_2();
    //Number_3();
   // Number_4();
    //Number_5();
}