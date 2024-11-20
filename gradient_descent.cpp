#include <iostream>
#include <cmath> // Pour std::abs dans le cas où tu souhaiterais implémenter des conditions d'arrêt basées sur la précision

// Fonction fitness qui correspond à f(x) = x^2, utilisant long long
long long fitness(long long x) {
    return x * x;
}

// Dérivée de la fonction fitness f'(x) = 2*x, utilisant long long
long long fitness_derivative(long long x) {
    return 2 * x;
}

int main() {
    srand(time(0));

    long long x = rand() % 100; // Début avec une valeur initiale aléatoire pour x
    double learning_rate = 0.01; // Taux d'apprentissage pour la mise à jour de x, réduit pour plus de contrôle
    int max_iterations = 100; // Nombre maximal d'itérations

    std::cout << "Valeur initiale de x : " << x << "\n";

    for (int i = 0; i < max_iterations; ++i) {
        x += (long long)(learning_rate * fitness_derivative(x)); // Mise à jour de x en fonction de la dérivée
        std::cout << "Iteration " << i + 1 << ": x = " << x << ", fitness = " << fitness(x) << "\n";
    }

    std::cout << "Valeur finale de x : " << x << " avec une fitness de " << fitness(x) << "\n";
    return 0;
}
