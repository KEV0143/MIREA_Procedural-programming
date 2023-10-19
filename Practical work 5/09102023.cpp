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

using namespace std;

int euclideanAlgorithm(int a, int b)
{
    int remainder;
    while (b != 0)
    {
        remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

void Number_1()
{
    int a, b;
    cout << "Введите два целых числа: ";

    while (!(cin >> a >> b) || a == 0 || b == 0)
    {
        cout << "Неверный ввод. Попробуйте снова: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int choice;
    cout << "Выберите алгоритм Евклида (1 - делением, 2 - вычитанием): ";

    while (!(cin >> choice))
    {
        cout << "Неверный ввод. Попробуйте снова: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int gcd;
    switch (choice)
    {
    case 1:
        gcd = euclideanAlgorithm(a, b);
        break;
    case 2:
        if (a < 0)
            a = -a;
        if (b < 0)
            b = -b;

        while (a != b)
        {
            if (a > b)
            {
                a -= b;
            }
            else {
                b -= a;
            }
        }
        gcd = a;
        break;
    default:
        cout << "Неверный выбор алгоритма.";
    }

    cout << "Наибольший общий делитель: " << gcd << endl;
}

void ERA(int n)
{
    vector <bool> prime(n + 1, true);

    prime[0] = false;
    prime[1] = false;

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }

    cout << "Простые числа до " << n << ": ";
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            cout << i << " ";
        }
    }
}

void Number_2()
{
    double n;
    cout << "Введите натуральное число: ";
    cin >> n;

    while (n <= 1 || floor(n) != n)
    {
        cin.clear();
        cin.ignore(numeric_limits <streamsize>::max(), '\n');
        if (n == 1)
        {
            cout << "Ошибка! Введите число больше 1: ";
        }
        else
        {
            cout << "Ошибка! Введите корректное натуральное число: ";
        }
        cin >> n;
    }

    ERA(static_cast<int>(n));
}

void Number_31() 
{
    ofstream file("31.txt");
    if (file.is_open()) {
        string text;
        cout << "Введите текст: ";
        getline(cin, text);
        file << text;
        file.close();
    }

    ifstream infile("31.txt");
    int consonants[26] = {};
    char c;
    bool foundConsonants = false;
    int maxCount = 0;
    char maxConsonant;

    while (infile >> c) 
    {
        if (isalpha(c) && !strchr("AEIOUaeiou", c)) 
        {
            consonants[toupper(c) - 'A']++;
            foundConsonants = true; 
        }
    }
    if (!foundConsonants) 
    { 
        cout << "Ошибка: в тексте не найдено согласных букв." << endl;
    }

    for (int i = 0; i < 26; i++) 
    {
        if (consonants[i] > maxCount) 
        {
            maxCount = consonants[i];
            maxConsonant = 'A' + i;
        }
    }
    cout << "Наиболее часто встречающаяся согласная буква: " << maxConsonant << endl;

}

void Number_32()
{
    ofstream file("32.txt");
    if (file.is_open()) {
        string text;
        cout << "Введите текст: ";
        getline(cin, text);
        file << text;
        file.close();
    }

    else 
    {
        cerr << "Ошибка открытия файла" << endl;
    }

    string filename;
    cout << "Введите имя файла: ";
    cin >> filename;

    ifstream file2(filename);
    if (!file2.is_open()) 
    {
        cerr << "Ошибка открытия файла" << endl;
    }

    map <char, int> freq;

    char c;
    while (file2.get(c)) {
        if (freq.find(c) == freq.end()) {
            freq[c] = 1;
        }
        else {
            freq[c]++;
        }
    }

    for (auto& pair : freq) {
        cout << "Символ '" << pair.first << "' встречается " << pair.second << " раз." << endl;
    }
}

string trans(string num, int startBase, int resultBase)
{
    const string digits = "0123456789ABCDEF";
    if (resultBase <= 1 || resultBase > 16) 
    {
        cout << "Ошибка";
        return "Ошибка";
    }

    int counter = 0;
    int result = 0;
    for (char c : num) {
        int charNum = digits.find(c);
        if (charNum >= startBase) {
            cout << "Ошибка";
            return "Ошибка";
        }
        result += charNum * pow(startBase, counter);
        counter++;
    }

    string final = "";
    while (result != 0) {
        int div = result % resultBase;
        result /= resultBase;
        final = digits[div] + final;
    }
    return final;
}

void Number_41() 
{
    cout << "Длина массива: ";
    int len;
    cin >> len;
    if (len <= 0) 
    {
        cout << "Ошибка"; return;
    }
    vector<string> vect(len);
    for (int i = 0; i < vect.size(); i++) {
        string a;
        cout << "Введите число с основанием 3: ";
        cin >> a;
        vect[i] = trans(a, 3, 6);
    }
    cout << "Массив равен: " << endl;
    for (int i = 0; i < vect.size(); i++) {
        cout << vect[i] << endl;
    }
}

int count_negative_triplets(vector<int> c, int n) {
    int count = 0;
    for (int i = 0; i < n - 2; i++) {
        int neg = 0; 
        for (int j = i; j < i + 3; j++) { 
            if (c[j] < 0) {
                neg++;
            }
        }
        if (neg == 3) { 
            count++;
        }
    }
    return count;
}

void Number_42() 
{
    vector<int> c(10);
    cout << "Введите число: ";

    for (int i2 = 0; i2 < 10; i2++) {
        cin >> c[i2];
    }
    int result = count_negative_triplets(c, 10);
    cout << "Количество троек отрицательных чисел: " << result << endl;
}
void Number_51()
{
    int kol, z, s, b;
    string c;
    vector <string> str(0);
    vector <int> zol(0);
    vector <int> ser(0);
    vector <int> bro(0);
    vector <int> vse(0);
    vector <int> bal(0);
    cout << "Введите колличество стран-участниц: ";
    cin >> kol;
    cout << "Введите названия стран: " << endl;
    for (int i = 0; i < kol; i++)
    {
        cin >> c;
        str.push_back(c);
    }

    sort(str.begin(), str.end());

    cout << "Введите колличество золотых, серебрянных, бронзовых медалей у: " << endl;
    for (int i = 0; i < kol; i++) 
    {
        cout << str[i] << ": ";
        cin >> z >> s >> b;
        zol.push_back(z);
        ser.push_back(s);
        bro.push_back(b);
        vse.push_back(z + s + b);
        bal.push_back(7 * z + 6 * s + 5 * b);

    }

    ofstream fout;
    fout.open("51.txt");
    for (int i = 0; i < kol; i++) {
        fout << str[i] << " " << zol[i] << " " << ser[i] << " " << bro[i] << " " << vse[i] << " " << bal[i];
        fout << endl;
    }
    ifstream ff2("51.txt");
    char buff[10000];
    if (ff2.is_open()) 
    {
        ff2.getline(buff, 10000);
        ff2.close();
        cout << buff << endl;
    }
}

struct Student 
{
    string id;
    string name;
    vector<pair<string, int>> subjects; 
};


bool compareStudents(const Student& s1, const Student& s2) 
{
    return s1.name < s2.name;
}

void Number_52() {
    ofstream file("52.txt"); 

    file << "12345 Климкин Иван Иванович Математика 5 Физика 4 Химия 3 Литература 5 История 4" << endl;
    file << "23456 Рысин Петр Петрович Математика 4 Физика 5 Химия 4 Литература 3 История 5" << endl;
    file << "34567 Дудин Алексей Владимирович Математика 3 Физика 4 Химия 5 Литература 5 История 4" << endl;
    file << "34567 Агеев Алексей Владимирович Математика 3 Физика 4 Химия 5 Литература 5 История 4" << endl;

    file.close(); 

    ifstream inputFile("52.txt");
    vector<Student> students; 


    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        Student student;
        iss >> student.id >> student.name;

        string subject;
        int grade;
        while (iss >> subject >> grade) {
            student.subjects.push_back(make_pair(subject, grade));
        }

        students.push_back(student);
    }

    inputFile.close();

    sort(students.begin(), students.end(), compareStudents);

    for (const auto& student : students) {
        cout << "Номер зачетной книжки: " << student.id << endl;
        cout << "ФИО студента: " << student.name << endl;
        cout << "Предметы и оценки: ";
        for (const auto& subject : student.subjects) {
            cout << subject.first << " " << subject.second << " ";
        }
        cout << endl << endl;
    }

}



int main()
{
    setlocale(0, "Russian");
   // Number_1();
   // Number_2();
   // Number_31();
   // Number_32();
   // Number_41();
   // Number_42();
   // Number_51();
   Number_52();

}