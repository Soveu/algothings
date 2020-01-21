#include <iostream>
#include <stdint.h>

#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cmath>

#define DEBUG_PRINT(x) (x)

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;

  std::vector<int> v(n);
  for(auto& x : v) {
    std::cin >> x;
  }

  auto med = v.begin() + v.size()/2;
  std::nth_element(v.begin(), med, v.end());
  std::cout << *med << '\n';

  return 0;
}

