#include <iostream>
#include <limits>

using namespace std;

// Функция для вычисления количества ситуаций
unsigned int countS(unsigned int n)
{
    // Базовый случай: для n=1 и n=2 возвращаем 1
    if (n == 1 || n == 2)
    {
        return 1;
    }

    // Инициализация переменных для хранения значений в последовательности
    unsigned int kn_minus_2 = 1; // k1
    unsigned int kn_minus_1 = 1; // k2
    unsigned int kn; // текущее kn

    // Цикл для вычисления значений последовательности от 3 до n
    for (unsigned int i = 3; i <= n; ++i)
    {
        // Формула для вычисления текущего значения
        kn = (kn_minus_1 + kn_minus_2) * (i - 1);

        // Обновление предыдущих значений для следующей итерации
        kn_minus_2 = kn_minus_1;
        kn_minus_1 = kn;
    }

    // Возвращение последнего значения в последовательности
    return kn;
}

// Основная программа
int main()
{
    setlocale(LC_ALL, "Russian");

    // Ввод значения n с клавиатуры
    double input;
    cout << "Введите [ n ] - исходное количество шариков: ";

    // Проверка на ввод положительных целых чисел
    while (true)
    {
        cin >> input;

        if (cin.fail() || input <= 0 || input != static_cast<int>(input))
        {
            cin.clear(); // сброс флага ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очистка ввода
            cout << "Пожалуйста, введите положительное целое число: ";
        }
        else
        {
            break;
        }
    }

    // Приведение типа и вызов функции для вычисления количества ситуаций
    unsigned int n = static_cast<unsigned int>(input);
    unsigned int result = countS(n);

    // Вывод результата на экран
    cout << "[ k ] - искомое количество ситуаций: " << result << endl;
}
