#include <iostream>
#include <vector>
#include <random>
#include <string>
using namespace std;

struct Pig
{
	string geneticCode;
	bool isSick;
	string disease;
	int hunger; // уровень сытости
	int thirst; // уровень жажды
};

int main()
{
	setlocale(LC_ALL, "Russian");
	vector <Pig> population;

	// Список болезней
	vector <string> diseases = { "Свинной грип", "Чума", "Сальмонеллез" };

	// Генератор случайных чисел
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> distribution(0, 1);
	uniform_int_distribution<int> hungerDistribution(0, 100);
	uniform_int_distribution<int> thirstDistribution(0, 100);

	// Создание начальной популяции из 10 свиней
	for (int i = 0; i < 10; ++i)
	{
		Pig pig;
		pig.geneticCode = "";

		// Генерация случайного генетического кода длиной 10 символов
		for (int j = 0; j < 10; ++j)
		{
			pig.geneticCode += to_string(distribution(gen));
		}

		pig.isSick = (distribution(gen) == 0); // генерация случайного заболевания
		if (pig.isSick)
		{
			// Выбор случайной болезни из списка
			uniform_int_distribution<int> diseaseDistribution(0, diseases.size() - 1);
			pig.disease = diseases[diseaseDistribution(gen)];
		}

		pig.hunger = hungerDistribution(gen); // случайный уровень сытости
		pig.thirst = thirstDistribution(gen); // случайный уровень жажды

		population.push_back(pig);
	}

	// Вывод генетического кода, состояния здоровья, уровня сытости и жажды каждой свиньи
	for (int i = 0; i < population.size(); ++i)
	{
		cout << " | Генетический код свинки " << i << ": | " << population[i].geneticCode;

		if (population[i].isSick)
		{
			cout << " | Состояние здоровья: БОЛЕЕТ (" << population[i].disease << ") \n";
		}
		else
		{
			cout << " | Состояние здоровья: ЗДОРОВА \n";
		}

		cout << " | Уровень сытости: " << population[i].hunger;
		cout << " | Уровень жажды: " << population[i].thirst << "\n\n";

		// Проверка на смерть свиней
		if (population[i].hunger < 20 || population[i].thirst < 20)
		{
			population.erase(population.begin() + i);
			cout << " [*] Свинья " << i << " умерла от голода или жажды \n\n";
		}
	}
}

