#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
  string name;
  int age;
  Person(string n, int a) : name(n), age(a) {}
};

struct Comparator {
  bool operator()(Person &a, Person &b) { return a.age < b.age; }
};

int main() {
  priority_queue<Person, vector<Person>, Comparator> pq;
  pq.push(Person("mazi", 30));
  pq.push(Person("jige", 50));
  pq.push(Person("lizhe", 40));

  while (!pq.empty()) {
    auto p = pq.top();
    cout << p.name << ", " << p.age << endl;
    pq.pop();
  }
}
