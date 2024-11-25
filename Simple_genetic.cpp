#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

struct Animal {
    double speed;         // Vitesse de déplacement
    double efficiency;    // Efficacité alimentaire
    double foodCollected; // Quantité de nourriture collectée
    double fitness;       // Fitness basée sur la quantité de nourriture collectée

    // Constructeur qui initialise les attributs aléatoirement
    Animal() : foodCollected(0), fitness(0) {
        speed = (double) rand() / RAND_MAX;
        efficiency = (double) rand() / RAND_MAX;
    }

    // Fonction pour manger
    void eat(double foodAvailable) {
        double foodEaten = std::min(foodAvailable, speed * efficiency);
        foodCollected += foodEaten;
        fitness = foodCollected; // Plus il mange, plus sa fitness est élevée
    }
};

// Comparer les animaux par fitness
bool compareByFitness(const Animal& a, const Animal& b) {
    return a.fitness > b.fitness;
}

// Mutation pour introduire des variations génétiques
void mutate(Animal& animal) {
    animal.speed += ((double) rand() / RAND_MAX - 0.5) * 0.1;
    animal.efficiency += ((double) rand() / RAND_MAX - 0.5) * 0.1;
    animal.speed = std::max(0.0, std::min(animal.speed, 1.0)); // Garder la vitesse dans l'intervalle [0, 1]
    animal.efficiency = std::max(0.0, std::min(animal.efficiency, 1.0)); // De même pour l'efficacité
}

int main() {
    srand(time(0));
    int populationSize = 100;
    int generations = 50;
    double totalFoodPerDay = 50.0; // Quantité totale de nourriture disponible par jour

    std::vector<Animal> population(populationSize);

    // Processus d'évolution
    for (int gen = 0; gen < generations; ++gen) {
        // Phase de nourrissage
        for (Animal& animal : population) {
            animal.eat(totalFoodPerDay / populationSize); // Chaque animal essaie de manger
        }

        // Trier les animaux par fitness et garder les meilleurs
        std::sort(population.begin(), population.end(), compareByFitness);
        population.resize(populationSize / 2); // Survie du plus apte

        // Reproduction et mutation
        int currentSize = population.size();
        for (int i = 0; i < currentSize; ++i) {
            Animal child = population[i];
            mutate(child);
            population.push_back(child); // Ajouter l'enfant à la population
        }

        // Remplir la population si nécessaire
        while (population.size() < populationSize) {
            population.push_back(Animal());
        }
    }

    // Affichage du meilleur animal
    std::cout << "Best fitness: " << population[0].fitness << std::endl;
    std::cout << "Speed: " << population[0].speed << ", Efficiency: " << population[0].efficiency << std::endl;

    return 0;
}
