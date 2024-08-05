#include <vector>
#include <iostream>

double calculate_rate(const std::vector<double>& contracts) {
    if (contracts.empty()) {
        std::cerr << "Error: The contracts vector is empty." << std::endl;
        return 0.0;
    }

    double sum = 0.0;
    for (double value : contracts) {
        sum += value;
    }
    return sum / contracts.size();
}