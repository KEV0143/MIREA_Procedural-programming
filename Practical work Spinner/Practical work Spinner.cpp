#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Spinner_1() 
{
    int A, B, C;
    cin >> A >> B >> C;
    int N = (C - A) / B;
    cout << N << endl;
}

void Spinner_2()
{
    int n;
    int count_3 = 0, count_4 = 0;

    cout << "Введите количество лопастей: ";
    cin >> n;

    while (n >= 3) 
    {
        if (n % 3 == 0) 
        {
            count_3++;
            n -= 3;
        }
        else {
            count_4++;
            n -= 4;
        }
    }
    cout << count_3 << " " << count_4 << endl;
}

void Spinner_3()
{
    int n, m;
    cin >> n >> m;
    long long ans = 0;
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= m; j++) 
        {
            ans += (n - i + 1) * (m - j + 1); // формула для количества прямоугольников
        }
    }
    cout << ans << endl;
}

void Spinner_4()
{
    int n;
    cout << "Введите количество свободных мест: ";
    cin >> n;
    vector <int> seats(n);
    for (int i = 0; i < n; i++)
    {
        cin >> seats[i];
    }

    sort(seats.begin(), seats.end()); // сортировка номера свободных мест
    int max_coupes = 0;
    int coupes = 0;
    int coupe = 0;
    
    for (int i = 0; i < n; i++)
    {
        int it_coupe = (seats[i] - 1) / 4; // номер купе для текущего свободного места
        if (seats[i] >= 37) // если свободное место находится справа от прохода
        {
            it_coupe = 8 - it_coupe; // противоположная нумерация купе
        }
        if (i == 0 || it_coupe == coupe + 1) // текущее свободное место идет за предыдущим в подряд идущем купе
        {
            coupes++;
        }
        else {
            max_coupes = max(max_coupes, coupes); // максимальное число подряд идущих купе
            coupes = 0;
        }
        coupe = it_coupe;
    }
    max_coupes = max(max_coupes, coupes); // последнее последовательность купе
    cout << max_coupes << endl;
}

void Spinner_5() 
{
    int N, K;
    cout << "N: ";
    cin >> N;
    cout << "K: ";
    cin >> K;
    
    while (K != 1) 
    {
        N = (N - K % 2) / 2;
        K = K / 2;
    }

    cout << (N - 1) / 2 << endl;
    cout << N / 2 << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    // Spinner_1();
    // Spinner_2();
    // Spinner_3();
    // Spinner_4();
    Spinner_5();
}