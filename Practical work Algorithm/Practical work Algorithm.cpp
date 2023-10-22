#include <iostream>
using namespace std;
// 5. Сортировка выбором (отбором)

void selectionSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int arr[] = { 64, 25, 12, 22, 11, 33249, 1313, 111, 11, 0, 01, -1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
}

// Внутри функции происходит двойной цикл: внешний цикл перебирает элементы массива, а внутренний цикл находит минимальный элемент в оставшейся части массива. 
// Затем происходит обмен текущего элемента со значением минимального элемента. 
// После завершения сортировки, в функции main выводится отсортированный массив.