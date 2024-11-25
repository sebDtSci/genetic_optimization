#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

int fitness(int x) {
    return x * x;
}

int main() {
    srand(42); // Initialisation de la graine aléatoire identique

    const int population_size = 10;
    std::vector<int> population(population_size);

    // Génération de la population initiale
    for (int &individual : population) {
        individual = rand() % 100;
    }

    // Affichage de la population initiale pour comparaison
    std::cout << "Population initiale : ";
    for (const int &individual : population) {
        std::cout << individual << " ";
    }
    std::cout << "\n";

    for (int generation = 0; generation < 100; ++generation) {
        // Évaluation et tri de la population
        std::sort(population.begin(), population.end(), [](int a, int b) {
            return fitness(a) > fitness(b);
        });
        population.resize(population_size / 2);

        // Reproduction
        while (population.size() < population_size) {
            int parent1 = population[rand() % (population_size / 2)];
            int parent2 = population[rand() % (population_size / 2)];
            int child = (parent1 + parent2) / 2;
            population.push_back(child);
        }

        // Mutation
        for (int &individual : population) {
            if (rand() % 100 < 15) { // Augmentation de la probabilité de mutation
                individual += rand() % 20 - 10; // Augmentation de l'intensité de la mutation
            }
        }
    }

    std::cout << "Meilleur individu : " << population[0] << " avec une fitness de " << fitness(population[0]) << "\n";
    return 0;
}
