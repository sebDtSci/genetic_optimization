#include <iostream>
#include <cmath>

double fitness(double x) {
    return -x * x;
}

double gradient(double x) {
    return -2 * x;
}

int main() {
    double x = 50.0;  
    double learning_rate = 0.1; 
    int max_iterations = 100;  

    for (int i = 0; i < max_iterations; ++i) {
        double grad = gradient(x);
        x = x + learning_rate * grad; 
        std::cout << "Itération " << i << ": x = " << x << ", fitness = " << fitness(x) << "\n";
        if (std::abs(grad) < 1e-6) {
            break;
        }
    }
    std::cout << "Solution optimale : x = " << x << ", fitness = " << fitness(x) << "\n";
    return 0;
}
