/* Marx Tomasz */

#include <iostream>
#include <stdint.h>

#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cmath>

#define DEBUG_PRINT(x) (x)

std::vector<int> iota_vector(int n) {
  std::vector<int> v(n);
  for(int i=0; i<n; ++i) {
    v[i] = i+1;
  }
  return v;
}

std::set<int> iota_set(int n) {
  auto v = iota_vector(n);
  return std::set<int>(v.begin(), v.end());
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;
  
  auto candys = iota_set(n);
  for(int i=1; i<n; ++i) {
    int64_t each = n*(n*n+1) / 2;
    std::cout << "each=" << each << '\n';

    while(each > 0) {
      auto it = candys.lower_bound(each);
      if(it == candys.end()) {
        std::cout << *it << '\n';
        --it;
      }

      each -= *it;
      std::cout << "each=" << each << '\n';
      std::cout << *it << ' ';
      candys.erase(it);
    }
    std::cout << '\n';
  }

  for(const int x : candys) {
    std::cout << x << ' ';
  }
  std::cout << '\n';

  return 0;
}

