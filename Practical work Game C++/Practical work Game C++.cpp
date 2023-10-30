#include <iostream>
#include <vector>
#include <random>
#include <string>

using namespace std;

struct Pig {
    int number;
    string geneticCode;
    int hunger; // уровень сытости
    int thirst; // уровень жажды
    int age; // возраст свиньи
};

bool isPigDead(const Pig& pig) {
    return pig.hunger <= 20 || pig.thirst <= 20 || pig.age > 15;
}

int main() {
    setlocale(LC_ALL, "Russian");

    vector<Pig> population;
    vector<Pig> nextGeneration; // Для следующего поколения

    // Генератор случайных чисел
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> changeDistribution(-10, 10); // Диапазон изменения сытости и жажды
    uniform_int_distribution<int> initialHungerDistribution(0, 100); // Начальный уровень сытости
    uniform_int_distribution<int> initialThirstDistribution(0, 100); // Начальный уровень жажды
    uniform_int_distribution<int> geneticCodeDistribution(100000, 999999); // Генетический код

    int generation = 1;
    int bornCount = 0;
    int diedCount = 0;

    int initialPopulationSize;
    cout << "Введите начальное количество свиней: ";
    cin >> initialPopulationSize;

    // Создание начальной популяции с заданным количеством свиней
    for (int i = 0; i < initialPopulationSize; ++i) {
        Pig pig;
        pig.number = i + 1;
        pig.geneticCode = to_string(geneticCodeDistribution(gen)); // Генерация случайного генетического кода
        pig.hunger = initialHungerDistribution(gen);
        pig.thirst = initialThirstDistribution(gen);
        pig.age = 1; // Возраст в первом поколении начинается с 1
        population.push_back(pig);
    }

    int reproductionChance;
    cout << "Введите шанс на потомство (0-100%): ";
    cin >> reproductionChance;

    while (true) {
        cout << "Поколение " << generation << ":\n";

        // Вывод информации о свиньях текущего поколения и проверка на смерть
        for (int i = 0; i < population.size(); ++i) {
            cout << " | Номер свиньи: " << population[i].number;
            cout << " | Генетический код: " << population[i].geneticCode;
            cout << " | Возраст: " << population[i].age;
            cout << " | Уровень сытости: " << population[i].hunger;
            cout << " | Уровень жажды: " << population[i].thirst;

            if (isPigDead(population[i])) {
                cout << " | [*] Умерла";
                diedCount++;
            }
            else {
                // Если свинья выжила, добавляем её в следующее поколение
                nextGeneration.push_back(population[i]);

                // С шансом на потомство свинья может родить потомство, при условии, что в текущем поколении живы две свиньи
                if (gen() % 100 < reproductionChance && nextGeneration.size() >= 2) {
                    Pig child;
                    child.number = generation * 10 + i + 1;
                    child.geneticCode = to_string(geneticCodeDistribution(gen)); // Генетический код
                    child.hunger = 100; // Уровень сытости новорожденной свинки равен 100
                    child.thirst = 100; // Уровень жажды новорожденной свинки равен 100
                    child.age = 1; // Возраст новорожденной свинки
                    nextGeneration.push_back(child);
                    bornCount++;
                    cout << " | [*] Родила потомство";
                }
            }

            cout << "\n\n";
        }

        // Заменяем текущее поколение следующим
        population = nextGeneration;
        nextGeneration.clear();

        // Генерация новых значений голода и жажды для следующего поколения с ограничением до максимума 100
        for (Pig& pig : population) {
            pig.hunger = min(100, max(0, pig.hunger + changeDistribution(gen)));
            pig.thirst = min(100, max(0, pig.thirst + changeDistribution(gen)));
            pig.age++; // Увеличение возраста свиньи
        }

        if (population.size() <= 1) {
            cout << "Осталась 1 свинья | Прожито " << generation << " поколений.\n" << endl;
            break;
        }

        generation++;
    }

    // Вывод сводки
    cout << "Итоговая сводка:\n";
    cout << "Всего родилось свиней: " << bornCount << endl;
    cout << "Всего умерло свиней: " << diedCount << endl;

    return 0;
}
