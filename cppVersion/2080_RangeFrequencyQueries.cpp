#include <climits>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class RangeFreqQuery {
public:
  unordered_map<int, vector<vector<int>>> rangeFreqMap;
  RangeFreqQuery(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
      if (rangeFreqMap.find(arr[i]) == rangeFreqMap.end()) {
        rangeFreqMap.insert({arr[i], {{i}}});
      } else {
        vector<int> &v = rangeFreqMap[arr[i]].back();
        if (i == v.back() + 1) {
          if (v.size() == 2) {
            v.back() = i;
          } else {
            v.push_back(i);
          }
        } else {
          rangeFreqMap[arr[i]].push_back({i});
        }
      }
    }
  }

  int query(int left, int right, int value) {
    int result = 0;
    if (rangeFreqMap.find(value) != rangeFreqMap.end() &&
        !rangeFreqMap[value].empty()) {
      vector<vector<int>> &v = rangeFreqMap[value];
      int leftIndex = 0;
      int rightIndex = v.size() - 1;
      int midIndex;
      while (leftIndex <= rightIndex) {
        midIndex = (leftIndex + rightIndex) / 2;
        vector<int> midVec = v[midIndex];
        if (midVec.front() <= left && midVec.back() >= left) {
          break;
        } else if (left <= midVec.front()) {
          rightIndex = midIndex - 1;
        } else if (left >= midVec.back()) {
          leftIndex = midIndex + 1;
        }
      }

      bool isLeftSet = false;
      for (int i = midIndex; i < v.size(); i++) {
        if (left <= v[i].back()) {
          isLeftSet = true;
        }
        if (left >= v[i].front() && left <= v[i].back()) {
          if (right > v[i].back()) {
            result += v[i].back() - left + 1;
            continue;
          } else {
            result += right - left + 1;
            return result;
          }
        }

        if (!isLeftSet)
          continue;

        if (v[i].back() >= right && v[i].front() <= right) {
          result += right - v[i].front() + 1;
          return result;
        } else if (right < v[i].front()) {
          return result;
        } else {
          result += v[i].back() - v[i].front() + 1;
        }
      }
    }
    return result;
  }
};

int main() {
  // [[[12,33,4,56,22,2,34,33,22,12,34,56]],[1,2,4],[0,11,33]]
  vector<int> v = {8, 4, 2, 5, 4, 5, 8, 6, 2, 3};
  RangeFreqQuery rfq(v);
  cout << rfq.query(6, 8, 4) << endl;
}





