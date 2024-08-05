import time
import python_api

def calculate_rate(contracts):
    if not contracts:
        print("Error: The contracts list is empty.")
        return 0.0

    total = sum(contracts)
    return total / len(contracts)

contracts = [i for i in range(1, 101)]

iterations = 100000

python_total_time = 0.0
for _ in range(iterations):
    start_time_python = time.time()
    python_rate = calculate_rate(contracts)
    end_time_python = time.time()
    python_total_time += (end_time_python - start_time_python)

average_python_time = python_total_time / iterations

cpp_total_time = 0.0
for _ in range(iterations):
    start_time_cpp = time.time()
    cpp_rate = python_api.calculate_rate(contracts)
    end_time_cpp = time.time()
    cpp_total_time += (end_time_cpp - start_time_cpp)

average_cpp_time = cpp_total_time / iterations

print('Calculated Python Rate:', python_rate)
print('Average Python execution time:', average_python_time, 'seconds')

print('Calculated C++ Rate:', cpp_rate)
print('Average C++ execution time:', average_cpp_time, 'seconds')