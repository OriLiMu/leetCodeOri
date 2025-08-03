#include <iostream>
#include <string>
#include <unordered_map>

int main() {
  std::unordered_map<std::string, int> fruitStock = {
      {"apple", 5}, {"orange", 3}, {"banana", 7}};

  // 1. Simple presence check
  if (fruitStock.contains("apple")) {
    std::cout << "We have apples.\n";
  }

  // 2. Conditional insertion (only when absent)
  const std::string kiwiKey = "kiwi";
  if (!fruitStock.contains(kiwiKey)) {
    fruitStock.emplace(kiwiKey, 10);
  }

  // 3. Safe read (avoid accidental insertion via operator[])
  const std::string grapeKey = "grape";
  if (fruitStock.contains(grapeKey)) {
    std::cout << grapeKey << " count = " << fruitStock.at(grapeKey) << '\n';
  } else {
    std::cout << grapeKey << " not in stock.\n";
  }

  // 4. Bulk check
  for (const auto &item : {"banana", "pear", "orange"}) {
    std::cout << item << (fruitStock.contains(item) ? " ✔\n" : " ✖\n");
  }

  return 0;
}
