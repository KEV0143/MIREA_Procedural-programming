#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void Number_1() 
{
    int i = 0; 
    double sum = 0;
    double digital = 0;

    ofstream file("1.txt");
    while (i != 10) 
    { 
        i += 1;
        cout << i << ") ";
        if (cin >> digital) 
        { 
            file << digital << "\n";
        }
        else {
            cout << "Некорректный ввод" << endl;
        }
    }
    file.close();

    ifstream ifile("1.txt");
    i = 0;
    while (i != 10) 
    { 
        ifile >> digital;
        sum += digital;
        i += 1;
    }
    ifile.close();

    cout << "Сумма чисел из файла = " << sum << endl;
}

int A(float x) 
{
    if (x > 0) 
    {
        return 1;
    }
    else if (x == 0) 
    {
        return 0;
    }
    return -1;
}

void Number_2() 
{
    double x = 0;
    while (true) 
    {
        cout << "x = ";
        if (cin >> x) 
        {
            cout << A(x) << endl;
        }
        else 
        {
            cout << "Некорректный ввод";
            break;
        }
    }
}

double pr (double a, double b)  // прямоугольник
{ 
    if (a <= 0 or b <= 0) 
    {
        return -1;
    }
    return a * b;
}

double tr (double a, double b, double c) // треугольник
{ 
    if (a <= 0 or b <= 0 or c <= 0 or a + b <= c or a + c <= b or b + c <= a) 
    {
        return -1;
    }
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double kr (double r)  // круг
{ 
    if (r <= 0) 
    {
        return -1;
    }
    return 3.14 * pow(r, 2);
}

void Number_3() 
{
    int select;
    double a, b, c, r;
    cout << "Выберите: 1 ( Прямоугольник ) / 2 ( Треугольник ) / 3 ( Круг ): ";
    cin >> select;
    switch (select) 
    {

    case 1: // прямоугольник
        cout << "Введите сторону a = ";
        cin >> a;
        cout << "Введите сторону b = ";
        cin >> b;
        if (pr(a, b) == -1) 
        {
            cout << "Некорректный ввод";
        }
        else 
        {
            cout << "Площадь прямоугольника = " << pr(a, b) << endl;
        }
        break;

    case 2: // треугольник
        cout << "Введите сторону a = ";
        cin >> a;
        cout << "Введите сторону b = ";
        cin >> b;
        cout << "Введите сторону c = ";
        cin >> c;
        if (tr(a, b, c) == -1) 
        {
            cout << "Некорректный ввод";
        }
        else 
        {
            cout << "Площадь треугольника = " << tr(a, b, c) << endl;
        }
        break;
    
    case 3: // круг
        cout << "Введите радиус круга = ";
        cin >> r;
        if (kr(r) == -1) 
        {
            cout << "Некорректный ввод";
        }
        else 
        {
            cout << "Площадь круга = " << kr(r) << endl;
        }
        break;
    default:
        cout << "Некорректный ввод";
    }
}

void Number_4()
{
    for (int i = 0; i < 8; i++) 
    {
        cout << "  *  *  *  *  *  *";
        cout << "_____________________" << endl;
    }

    for (int i = 0; i < 5; i++) 
    { 
        cout << "_______________________________________" << endl;
    }
}

void Number_5()
{
    const int width = 80; // ширина графика
    const int height = 30; // высота графика
    const double xMin = -3.14; // минимальное значение x
    const double xMax = 3.14; // максимальное значение x
    const double yMin = -1.0; // минимальное значение y
    const double yMax = 1.0; // максимальное значение y

    for (int i = 0; i < height; i++) 
    {
        double y = (double)i / height * (yMax - yMin) + yMin;
        for (int j = 0; j < width; j++) 
        {
            double x = (double)j / width * (xMax - xMin) + xMin;
            double sinX = sin(x);
            
            if (abs(sinX - y) < 0.05) 
            {
                cout << "*";
            }
            else if (i == height / 2 && j == width / 2) 
            {
                cout << "+";
            }
            else if (i == height / 2) 
            {
                cout << "-";
            }
            else if (j == width / 2) 
            {
                cout << "|";
            }
            else 
            {
                cout << " ";
            }
        }
        cout << endl;
    }

}


int Cifra(string s) 
{
    int result = 0;
    int rim = 0;
    for (int i = s.size() - 1; i >= 0; i--) 
    {
        int cif = 0;
        switch (s[i]) {
        case 'I': cif = 1; break;
        case 'V': cif = 5; break;
        case 'X': cif = 10; break;
        case 'L': cif = 50; break;
        case 'C': cif = 100; break;
        case 'D': cif = 500; break;
        case 'M': cif = 1000; break;
        }
        if (cif < rim) {
            result -= cif;
        }
        else {
            result += cif;
        }
        rim = cif;
    }
    return result;
}

void Number_6()
{
    string Cifra1;
    cout << "Введите римскую цифру: ";
    cin >> Cifra1;
    int decit = Cifra(Cifra1);
    cout << "Декодирование: " << Cifra1 << " -> " << decit << endl;
}

int cI(char c) {
    if (c >= '0' && c <= '9') 
    {
        return c - '0';
    }
    else {
        return c - 'A' + 10;
    }
}

char iC(int n) 
{
    if (n >= 0 && n <= 9) {
        return n + '0';
    }
    else {
        return n - 10 + 'A';
    }
}

string osnov(string num, int oldosn, int newosn) 
{
    string result = "";
    int decimalNum = 0;
    int power = 1;
    for (int i = num.size() - 1; i >= 0; i--) 
    {
        int digit = cI(num[i]);
        decimalNum += digit * power;
        power *= oldosn;
    }
    while (decimalNum > 0) {
        int digit = decimalNum % newosn;
        result = iC(digit) + result;
        decimalNum /= newosn;
    }
    return result;
}

void Number_9() 
{
    string num;
    int oldosn, newosn;
    cout << "Введите число: ";
    cin >> num;
    cout << "Введите старое основание: ";
    cin >> oldosn;
    cout << "Введите новое основание: ";
    cin >> newosn;
    string result = osnov(num, oldosn, newosn);
    cout << "Результат " << result << endl;
}
int main()
{
    setlocale(0, "Russian");
    //Number_1();
    //Number_2();
    //Number_3();
    //Number_4();
    //Number_5();
    //Number_6();
    Number_9();

}