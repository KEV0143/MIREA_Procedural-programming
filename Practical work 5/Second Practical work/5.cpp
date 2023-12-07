#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <string>
#include <cctype>
#include <sstream>
#include <unordered_map>
#include <cstdlib>
#include <ctime>

using namespace std;

int gcd(int x, int y)
{
    int r;
    while (y != 0)
    {
        r = x % y;   // Находим остаток от деления x на y.
        x = y;       // Присваиваем y в x.
        y = r;       // Присваиваем остаток в y для следующей итерации.
    }
    return x;       // Возвращаем значение x, которое является наибольшим общим делителем.
}

void Num1()
{
    int m, n;
    cout << "Два числа: ";

    // Проверка ввода двух чисел
    while (!(cin >> m >> n) || m == 0 || n == 0)
    {
        cout << "Неверный ввод. ";
        cin.clear();  // Очистка флагов ошибок ввода
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Игнорирование оставшихся символов до новой строки
    }

    int ch;
    cout << "Алгоритм Евклида | 1 деление, 2 - вычитание: ";

    // Проверка ввода выбора алгоритма
    while (!(cin >> ch))
    {
        cout << "Неверный ввод. ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int g;
    // Выбор алгоритма в зависимости от введенного значения
    switch (ch)
    {
    case 1:
        g = gcd(m, n);
        break;
    case 2:
        // Алгоритм вычитания (если второе число отрицательное, делаем его положительным)
        if (m < 0)
            m = -m;
        if (n < 0)
            n = -n;

        while (m != n)
        {
            if (m > n)
            {
                m -= n;
            }
            else {
                n -= m;
            }
        }
        g = m;
        break;
    default:
        cout << "Неверный выбор алгоритма.";
    }

    cout << "Наибольший общий делитель: " << g << endl;
}

void NUM(int n)
{
    // Создание вектора булевых значений matr размером n+1, все инициализированы как true
    vector <bool> matr(n + 1, true);

    // Установка matr[0] и matr[1] в false, так как 0 и 1 не являются простыми числами
    matr[0] = false;
    matr[1] = false;

    // Просмотр чисел от 2 до корня из n
    for (int p = 2; p * p <= n; p++)
    {
        // Проверка, является ли число p простым
        if (matr[p] == true)
        {
            // Обновление значений вектора matr для кратных p
            for (int i = p * p; i <= n; i += p)
            {
                matr[i] = false;
            }
        }
    }

    // Вывод простых чисел до n
    cout << "Простые числа до " << n << ": ";
    for (int i = 2; i <= n; i++)
    {
        if (matr[i])
        {
            cout << i << " ";
        }
    }
}


void Num2()
{
    double n;
    cout << "Натуральное число: ";
    cin >> n;

    // Проверка введенного числа
    while (n <= 1 || floor(n) != n)
    {
        cin.clear();  // Очистка флагов ошибок ввода
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Игнорирование оставшихся символов до новой строки

        // Вывод сообщения об ошибке в зависимости от условий
        if (n == 1)
        {
            cout << "Введите число > 1: ";
        }
        else
        {
            cout << "Число некорректное или ненатуральное: ";
        }

        cin >> n;  // Повторный ввод числа
    }

    NUM(static_cast<int>(n));  // Вызов функции NUM с преобразованием введенного числа в int
}


void Num31(const string& filename)
{
    // Открываем файл для чтения
    ifstream infile(filename);

    // Проверяем, удалось ли открыть файл
    if (!infile.is_open())
    {
        cerr << "Ошибка: Не удалось открыть файл." << endl;
        return;  // Выходим из функции, если файл не удалось открыть
    }

    // Создаем хэш-таблицу для хранения частот повторения символов
    unordered_map<char, int> Simvol;

    // Объявляем переменную для считывания символов из файла
    char c;

    // Считываем символы из файла по одному
    while (infile.get(c))
    {
        // Проверяем, является ли символ буквой
        if (isalpha(c))
        {
            // Если символ буквенный, увеличиваем счетчик его повторений в хэш-таблице
            Simvol[toupper(c)]++;
        }
    }

    // Закрываем файл
    infile.close();

    // Выводим частоту повторения символов в файле
    cout << "Частота повторения символов в файле:" << endl;
    for (const auto& pair : Simvol)
    {
        // Выводим символ и его частоту
        cout << "'" << pair.first << "': " << pair.second << endl;
    }
}

void Num32(const string& filename)
{
    // Открываем файл для чтения
    ifstream infile(filename);

    // Проверяем, удалось ли открыть файл
    if (!infile.is_open())
    {
        cerr << "Ошибка: Не удалось открыть файл." << endl;
        return;  // Выходим из функции, если файл не удалось открыть
    }

    // Создаем вектор для хранения слов
    vector<string> words;

    // Создаем строку для хранения каждого слова
    string word;

    // Читаем слова из файла
    while (infile >> word)
    {
        // Удаляем знаки препинания из слова
        word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());

        // Если слово не пустое, делаем первую букву заглавной и добавляем его в вектор
        if (!word.empty())
        {
            word[0] = toupper(word[0]);
        }
        words.push_back(word);
    }

    // Закрываем файл
    infile.close();

    // Сортируем вектор слов по алфавиту
    sort(words.begin(), words.end());

    // Выводим отсортированные слова на экран
    cout << "Слова в файле, отсортированные по алфавиту:" << endl;
    for (const auto& w : words) {
        cout << w << " ";
    }
    cout << endl;
}


void Num41() 
{  
    float e;
    cin >> e;
    double n = 1;
    double sum = 0;
        while (true) 
        {
            if ((1 / (pow(3, n))) < e){
                break;
            }
            sum += (1/(pow(3, n)) * pow(cos(pow(3, n-1)), 3));
            n++;
        }
        cout << "Result: " << sum << endl;
        
}

void Num42() 
{
    // Инициализация генератора случайных чисел
    srand(time(0));

    // Задание размера массива
    const int size = 96;

    // Задание массива для хранения случайных чисел
    int numbers[size];

    // Генерация случайных чисел и заполнение массива
    for (int i = 0; i < size; ++i) {
        numbers[i] = rand() % 201 - 100; // генерация чисел от -100 до 100
    }

    // Вывод сгенерированных чисел
    cout << "Сгенерированные числа: ";
    for (int i = 0; i < size; ++i) 
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    // Подсчет трех идущих подряд отрицательных чисел
    int count = 0;
    for (int i = 0; i < size - 2; ++i) 
    {
        if (numbers[i] < 0 && numbers[i + 1] < 0 && numbers[i + 2] < 0) 
        {
            count++;
        }
    }

    // Вывод результата
    cout << "Количество трех идущих подряд отрицательных чисел: " << count << endl;
}

void Num5()
{
    int kol, z, s, b;  // Объявление переменных: kol - количество стран, z - количество золотых медалей, s - серебрянных медалей, b - бронзовых медалей.
    string c;  // Строка для хранения названия страны.

    // Векторы для хранения данных по каждой стране.
    vector<string> str(0);  // Вектор для названий стран.
    vector<int> zol(0);     // Вектор для количества золотых медалей.
    vector<int> ser(0);     // Вектор для количества серебрянных медалей.
    vector<int> bro(0);     // Вектор для количества бронзовых медалей.
    vector<int> vse(0);     // Вектор для общего количества медалей.
    vector<int> bal(0);     // Вектор для подсчета баллов.

    cout << "Введите количество стран-участниц: ";
    cin >> kol;  // Ввод количества стран.

    cout << "Введите названия стран: " << endl;
    for (int i = 0; i < kol; i++) {
        cin >> c;  // Ввод названия страны.
        str.push_back(c);  // Добавление названия страны в вектор.
    }

    sort(str.begin(), str.end());  // Сортировка вектора с названиями стран в алфавитном порядке.

    cout << "Введите количество золотых, серебрянных, бронзовых медалей у: " << endl;
    for (int i = 0; i < kol; i++) {
        cout << str[i] << ": ";
        cin >> z >> s >> b;  // Ввод количества медалей для каждой страны.
        zol.push_back(z);  // Добавление количества золотых медалей в вектор.
        ser.push_back(s);  // Добавление количества серебрянных медалей в вектор.
        bro.push_back(b);  // Добавление количества бронзовых медалей в вектор.
        vse.push_back(z + s + b);  // Добавление общего количества медалей в вектор.
        bal.push_back(7 * z + 6 * s + 5 * b);  // Добавление баллов в вектор.
    }

    ofstream fout;  // Объект для записи в файл.
    fout.open("51.txt");  // Открытие файла для записи.
    for (int i = 0; i < kol; i++) {
        fout << str[i] << " " << zol[i] << " " << ser[i] << " " << bro[i] << " " << vse[i] << " " << bal[i];
        fout << endl;  // Запись данных по каждой стране в файл.
    }
    fout.close();  // Закрытие файла.

    ifstream ff2("51.txt");  // Объект для чтения из файла.
    char buff[10000];  // Буфер для считывания данных из файла.
    if (ff2.is_open()) {
        ff2.getline(buff, 10000);  // Считывание строки из файла.
        ff2.close();  // Закрытие файла.
        cout << buff << endl;  // Вывод строки на экран.
    }
}


int main() 
{
    setlocale(0, "Russian");
   //Num1();
    // Num2();
      //string filename31 = "31.txt";
     // Num31(filename31);
     //string filename32 = "32.txt";
      //Num32(filename32);
    // Num41(); 
    // Num42();
     Num5();
}