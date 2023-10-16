#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
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
            double sinX = tan(x);
            
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


void Number_6() 
{
    string directory = "C:/Users/KEV/Desktop/MIREA_Jobs-main/02102023/6.txt";
    string filename = "6.txt";

    cout << "Введите римскую цифру: ";
    string number;
    cin >> number;

    ifstream in(directory);
    if (in.is_open()) 
    {
        string line;
        while (getline(in, line)) 
        {
            string firstPart = "";
            string NUM = "";
            bool whasEq = false;
            bool secEq = false;

            for (char c : line) {
                if (c == '=') {
                    if (!whasEq) {
                        whasEq = true;
                    }
                    else {
                        secEq = true;
                        break;
                    }
                    continue;
                }
                if (whasEq) {
                    NUM += c;
                }
                else {
                    firstPart += c;
                }
            }

            if (number == NUM) {
                cout << firstPart << endl;
                return;
            }
        }
        cout << "Некорректный ввод, ошибка." << endl;
    }
    else {
        cout << "Ошибка дериктории." << endl;
    }
}

int random_number(int SI, int m, int i, int c) 
{
    return SI = (m * SI + i) % c;
}

void Number_7() 
{
    int SI = 1;
    int m, i, c;
    int variant;
    cout << "Выбирите вариант (1 или 2): ";
    cin >> variant;

    if (variant == 1) 
    {
        m = 37;
        i = 3;
        c = 64;
    }
    else if (variant == 2) 
    {
        m = 25173;
        i = 13849;
        c = 65537;
    }
    else 
    {
        cout << "Неправильный ввод" << endl;
    }

    for (int j = 0; j < 10; j++) 
    {
        cout << SI << endl;
        SI = random_number(SI, m, i, c);
    }
}

void Number_8()
{
    double a[3][4] =
    {
        {5, 2, 0, 10},
        {3, 5, 2, 5},
        {20, 0, 0, 0} };

    double b[4][2] =
    {
        {1.20, 0.50},
        {2.80, 0.40},
        {5.00, 1.00},
        {2.00, 1.50} };

    double c[3][2] = {};

    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 2; j++) 
        {
            for (int k = 0; k < 4; k++) 
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
        }
    }
    cout << endl;
    int maxSeller = 0;
    int minSeller = 0;
    double maxMoney = -1e9;
    double minMoney = 1e9;
    for (int i = 0; i < 3; i++) 
    {
        if (c[i][0] > maxMoney) 
        {
            maxSeller = i + 1;
            maxMoney = c[i][0];
        }
        if (c[i][0] < minMoney) 
        {
            minSeller = i + 1;
            minMoney = c[i][0];
        }
    }
    cout << " | Продавец " << maxSeller << " | Получил максимум денег: " << maxMoney << endl;
    cout << " | Продавец " << minSeller << " | Получил минимум денег: " << minMoney << endl;

    maxSeller = 0;
    minSeller = 0;
    double maxComss = -1e9;
    double minComss = 1e9;
    for (int i = 0; i < 3; i++) 
    {
        if (c[i][1] > maxComss) 
        {
            maxSeller = i + 1;
            maxComss = c[i][1];
        }
        if (c[i][1] < minComss) 
        {
            minSeller = i + 1;
            minComss = c[i][1];
        }
    }
    cout << " | Продавец " << maxSeller << " | Получил наибольшие комиссионные: " << maxComss << endl;
    cout << " | Продавец " << minSeller << " | Получил наименьшие комиссионные: " << minComss << endl;
    cout << endl;
    double sumMoney = 0.0;
    for (int i = 0; i < 3; i++) 
    {
        sumMoney += c[i][0];
    }
    cout << " | Общая сумма денег вырученная за проданные товары: " << sumMoney << endl;

    double sumComss = 0.0;
    for (int i = 0; i < 3; i++) 
    {
        sumComss += c[i][1];
    }
    cout << " | Всего комиссионных получили продавцы: " << sumComss << endl;

    double SumMoneyResult = 0.0;
    for (int i = 0; i < 3; i++)
    {
        SumMoneyResult += c[i][0] + c[i][1];
    }
    cout << " | Общая сумма денег прошедшая через руки продавцов: " << SumMoneyResult << endl;
}

int cI(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    else {
        return c - 'A' + 10;
    }
}

char iC(int n) {
    if (n >= 0 && n <= 9) {
        return n + '0';
    }
    else {
        return n - 10 + 'A';
    }
}

string osnov(string num, int oldosn, int newosn) {
    if (oldosn < 2 || oldosn > 16 || newosn < 2 || newosn > 16) {
        return "Основание должно быть в диапазоне от 2 до 16";
    }
    for (int i = 0; i < num.size(); i++) {
        if (cI(num[i]) >= oldosn) {
            return "Неправильное введённое число для заданного основания";
        }
    }
    string result = "";
    int decimalNum = 0;
    int power = 1;
    for (int i = num.size() - 1; i >= 0; i--)
    {
        int digit = cI(num[i]);
        decimalNum += digit * power;
        power *= oldosn;
    }
    while (decimalNum > 0)
    {
        int digit = decimalNum % newosn;
        result = iC(digit) + result;
        decimalNum /= newosn;
    }
    return result;
}

void Number_9() {
    string num;
    int oldosn, newosn;
    cout << "Введите число: ";
    cin >> num;
    cout << "Введите старое основание: ";
    cin >> oldosn;
    cout << "Введите новое основание: ";
    cin >> newosn;
    if (oldosn < 2 || oldosn > 36 || newosn < 2 || newosn > 36) {
        cout << "Основание должно быть в диапазоне от 2 до 36" << endl;
        return;
    }
    string result = osnov(num, oldosn, newosn);
    cout << "Результат: " << result << endl;
}

int main()
{
    setlocale(0, "Russian");
    //Number_1();
    //Number_2();
    //Number_3();
    //Number_4();
    //Number_5();
    Number_6();
    //Number_7();
    //Number_8();
    //Number_9();
}