#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

int fitness(int x) {
    return x * x;
}

int main() {
    srand(time(0));

    const int population_size = 10;
    std::vector<int> population(population_size);
    for (auto &individual : population) {
        individual = rand() % 100; 
    }

    for (int generation = 0; generation < 100; ++generation) {
        std::sort(population.begin(), population.end(), [](int a, int b) {
            return fitness(a) > fitness(b);
        });
        population.resize(population_size / 2);

        while (population.size() < population_size) {
            int parent1 = population[rand() % (population_size / 2)];
            int parent2 = population[rand() % (population_size / 2)];
            int child = (parent1 + parent2) / 2; 
            population.push_back(child);
        }

        for (auto &individual : population) {
            if (rand() % 100 < 5) { 
                individual += rand() % 10 - 5;
            }
        }
    }

    std::cout << "Meilleur individu : " << population[0] << " avec une fitness de " << fitness(population[0]) << "\n";
    return 0;
}
