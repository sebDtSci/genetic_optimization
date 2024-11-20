#include <iostream>
#include <cmath>

long long fitness(long long x) {
    return x * x;
}

long long fitness_derivative(long long x) {
    return 2 * x;
}

int main() {
    srand(42); // Initialisation de la graine aléatoire identique

    long long x = rand() % 100; // Valeur initiale de x identique au premier individu génétique
    double learning_rate = 0.01;
    int max_iterations = 100;

    std::cout << "Valeur initiale de x : " << x << "\n";

    for (int i = 0; i < max_iterations; ++i) {
        x += static_cast<long long>(learning_rate * fitness_derivative(x));
        std::cout << "Itération " << i + 1 << ": x = " << x << ", fitness = " << fitness(x) << "\n";
    }

    std::cout << "Valeur finale de x : " << x << " avec une fitness de " << fitness(x) << "\n";
    return 0;
}
