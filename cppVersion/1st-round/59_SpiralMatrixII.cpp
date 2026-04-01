#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    // right down left up, right ...
    vector<std::vector<int>> matrix(n, vector<int>(n));
    if (n == 1) {
      return {{1}};
    }
    int x = 0;
    int y = 0;
    vector<string> directions = {"right", "down", "left", "up"};
    string curDirection = directions[0];
    int currentDirectionIndex = 0;
    int currentValue = 1;
    int nextX = 0;
    int nextY = 0;
    int count = 1;
    while (true) {
      matrix[x][y] = currentValue;
      if (curDirection == "right") {
        nextY = y + 1;
      } else if (curDirection == "down") {
        nextX = x + 1;
      } else if (curDirection == "left") {
        nextY = y - 1;
      } else if (curDirection == "up") {
        nextX = x - 1;
      } else {
        cout << "error" << endl;
      }

      if (nextX < 0 || nextX > n - 1 || nextY < 0 || nextY > n - 1 ||
          matrix[nextX][nextY] != 0) {
        if (count == n * n) {
          return matrix;
        }
        nextX = x;
        nextY = y;
        currentDirectionIndex++;
        curDirection = directions[currentDirectionIndex % 4];
        continue;
      }

      currentValue++;
      x = nextX;
      y = nextY;
      count++;
    }
  }
};

int main() {
  Solution s;
  s.generateMatrix(3);
}
