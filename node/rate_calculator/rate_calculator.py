def calculate_rate(contracts):
    if not contracts:
        print("Error: The contracts list is empty.")
        return 0.0

    total = sum(contracts)
    return total / len(contracts)
