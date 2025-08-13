#include <iostream>
#include <queue>
#include <string>

class Person {
public:
  std::string name;
  int age;

  Person(std::string n, int a) : name(n), age(a) {}
};

// Comparator for max-heap by age
struct CompareAge {
  bool operator()(const Person &a, const Person &b) {
    return a.age < b.age; // For min-heap: `a.age > b.age`
  }
};

int main() {
  std::priority_queue<Person, std::vector<Person>, CompareAge> pq;

  pq.push(Person("Alice", 30));
  pq.push(Person("Bob", 20));
  pq.push(Person("Charlie", 40));

  while (!pq.empty()) {
    auto p = pq.top();
    std::cout << p.name << " (" << p.age << ")\n";
    pq.pop();
  }
  // Output:
  // Charlie (40)
  // Alice (30)
  // Bob (20)
  return 0;
}
