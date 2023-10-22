#include <iostream>
using namespace std;

void perestanovka(int* arr, int m, int n, int i, int& count)
{

    if (i == n) // перебрали все элементы массива
    {
        bool flag = false;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == j + 1)  // найдено совпадение
            {
                flag = true;
                break;
            }
        }
        if (flag) // одно совпадение = перестановка
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[j] << " ";
            }
            cout << endl;
            count++;
        }
    }
    else // оставшиеся элементы массива
    {
        for (int j = i; j < n; j++)
        {
            swap(arr[i], arr[j]);
            perestanovka(arr, m, n, i + 1, count);
            swap(arr[i], arr[j]);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    const int n = 10;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    int count = 0;
    perestanovka(arr, 1, n, 0, count);
    cout << "Общее количество перестановок, имеющих хотя бы одно совпадение: " << count << endl;
    return 0;
}

// 1 = 1 , 2 = 1 , 3 = 4 , 4  = 15 , 5 = 76 , 6 = 455 , 7 = 3186 , 8 = 25487 , 9 = 229384, 10 = 2293839  ... Перебор запущен в 12:24, искомый найден в 12:57 