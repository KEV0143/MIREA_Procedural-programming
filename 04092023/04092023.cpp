#include <iostream>
#include <Windows.h>
#include <iostream>
#include <cmath>
using namespace std;

void Number_1()
{
    cout << endl;
    cout << "[ Number 1 ] Меня зовут Егор." << endl;
    cout << endl;
}

void Number_2()
{
    double a, b;
    cout << "[ Number 2 ]" << endl;
    cout << "Введите число [ a ]: ";
    cin >> a;
    cout << "Введите число [ b ]: ";
    cin >> b;

    cout << endl;

    cout << "Сумма: " << a + b << endl;
    cout << "Разность: " << a - b << endl;
    cout << "Произведение: " << a * b << endl;

    if (b != 0)
    {
        cout << "Частное: " << a / b << endl;
        cout << endl;
    }

    else
    {
        cout << "Частное: Деление на 0 невозможно" << endl;
        cout << endl;
    }
}

void Number_3()
{
    double b, c;
    cout << "[ Number 3 ]" << endl;
    cout << "Введите значения b и c для уравнения bx + c = 0" << endl;

    cout << "Введите число [ b ]: ";
    cin >> b;
    cout << "Введите число [ c ]: ";
    cin >> c;

    if (b == 0)
    {
        if (c == 0)
        {
            cout << "Уравнение имеет бесконечно много решений" << endl;
            cout << endl;
        }
        else
        {
            cout << "Уравнение не имеет решений" << endl;
            cout << endl;
        }
    }
    else
    {
        double x = (-c / b);
        cout << "Решение уравнения: x = " << x << endl;
        cout << endl;
    }
}

void Number_4()
{
    double a, b, c, x1, x2, D;

    cout << "[ Number 4 ]" << endl;
    cout << "Введите значения a, b и c для уравнения ax^2 + bx + c = 0" << endl;

    cout << "Введите число [ a ]: ";
    cin >> a;
    cout << "Введите число [ b ]: ";
    cin >> b;
    cout << "Введите число [ c ]: ";
    cin >> c;

    if (a == 0)
    {
        if (b == 0)
        {
            cout << "Уравнение не является квадратным" << endl;
        }
        else
        {
            double x = (-c / b);
            cout << "Решение уравнения: x = " << x << endl;
        }
    }
    else
    {
        D = b * b - 4 * a * c;
        cout << "Дискриминант равен: " << D << endl;

        if (D > 0)
        {
            x1 = (-b + sqrt(D)) / (2 * a);
            x2 = (-b - sqrt(D)) / (2 * a);
            cout << "Уравнение имеет два корня: x1 = " << x1 << ", x2 = " << x2 << endl;
        }
        else if (D == 0)
        {
            x1 = -b / (2 * a);
            cout << "Уравнение имеет один корень: x = " << x1 << endl;
        }
        else
        {
            cout << "Уравнение не имеет корней" << endl;
        }
    }
    cout << endl;
}

void Number_5()
{
    bool day, sht, lamp;

    cout << "[ Number 5 ]" << endl;
    cout << "День ли на улице?" << endl;
    cout << "Введите [ 1 - да ] или [ 0 - нет ]: ";

    while (!(cin >> day) || (day != 0 && day != 1))
    {
        cout << "Ошибка ввода! 1 или 0! ";
        cin.clear();
    }

    if (day == 1)
    {
        day == true;
    }

    if (day == 0)
    {
        day == false;
    }

    cout << "Раздвинуты ли шторы?" << endl;
    cout << "Введите [ 1 - да ] или [ 0 - нет ]: ";

    while (!(cin >> sht) || (sht != 0 && sht != 1))
    {
        cout << "Ошибка ввода! 1 или 0! ";
        cin.clear();
    }

    if (sht == 1)
    {
        sht == true;
    }

    if (sht == 0)
    {
        sht == false;
    }

    cout << "Включена ли лампа?" << endl;
    cout << "Введите [ 1 - да ] или [ 0 - нет ]: ";

    while (!(cin >> lamp) || (lamp != 0 && lamp != 1))
    {
        cout << "Ошибка ввода! 1 или 0! ";
        cin.clear();
    }

    if (lamp == 1)
    {
        lamp == true;
    }

    if (lamp == 0)
    {
        lamp == false;
    }

    if (lamp == true)
    {
        cout << "В комнате: Светло";
    }

    else if (day == true and sht == true)
    {
        cout << "В комнате: Светло";
    }

    else
    {
        cout << "В комнате: Темно";
    }
}

int main()
{
    setlocale(0, "Russian");
    // Number_1();
    // Number_2();
    // Number_3();
    // Number_4();
    Number_5();
}