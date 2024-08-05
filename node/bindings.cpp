#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <vector>
#include "rate_calculator/rate_calculator.h"

namespace py = pybind11;

PYBIND11_MODULE(python_api, m) {
    m.def("calculate_rate", [](const std::vector<double>& contracts) {
        return calculate_rate(contracts);
    }, "Calculate the rate from a list of contracts");
}