#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>
#include <algorithm>

using namespace std;
using namespace chrono;

int main() {
  vector<int> v = {1, 2, 3};
  vector<int> c(32);
  for(auto& n: v){
    for(int i = 0; i < 32, i++){
      if(n && 1)
        c[i]++;
      n >>= 1;
    }
  }
  
  for(int i = 0; i < 32; i++)
    cout << i << " : " << c[i] << endl;
  return 0;
}
