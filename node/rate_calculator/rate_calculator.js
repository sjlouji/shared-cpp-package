function calculateRate(contracts) {
  if (contracts.length === 0) {
    console.error("Error: The contracts array is empty.");
    return 0.0;
  }

  let sum = contracts.reduce((acc, value) => acc + value, 0);
  return sum / contracts.length;
}
module.exports = calculateRate;