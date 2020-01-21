#include <iostream>
#include <stdint.h>

#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cmath>
#include <array>
#include <functional>

#define DEBUG_PRINT(x) (x)

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;

  std::vector<std::array<int, 5>> where(n);
  for(int i=0; i<5; ++i) {
    for(int j=0; j<n; ++j) {
      int x;
      std::cin >> x;
      where[x-1][i] = j;
    }
  }
  
  auto cmp = [&where](int a, int b) {
    int x = 0;
    for(int i=0; i<5; ++i) {
      x += (where[a][i] < where[b][i]);
    }
    return x >= 3;
  };
  
  std::vector<int> res(n);
  for(int i=0; i<n; ++i) {
    res[i] = i;
  }

  std::sort(res.begin(), res.end(), cmp);
  for(const auto& x : res) {
    std::cout << x+1 << ' ';
  }
  std::cout << '\n';

  return 0;
}

