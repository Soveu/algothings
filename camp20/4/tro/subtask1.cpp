#include <iostream>
#include <stdint.h>

#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cmath>

#define DEBUG_PRINT(x) (x)

const int BASE = 17;

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n, subtask;
  std::cin >> n;
  
  std::vector<std::pair<int, int>> ans;
  ans.reserve(10*n);

  int i = 0;
  for(; i+BASE<n; i += BASE) {
    for(int u=i; u<i+BASE; ++u) {
      for(int v=u+1; v<i+BASE; ++v) {
        ans.push_back({u, v});
      }
    }
  }

  for(; i<n; ++i) {
    for(int j=i+1; j<n; ++j) {
      ans.push_back({i, j});
    }
  }

  for(int u=BASE-1; u<n; u+=BASE) {
    for(int v=u+1; v<n; v+=BASE) {
      ans.push_back({u, v});
    }
  }

  std::cout << ans.size() << '\n';
  for(const auto& x : ans) {
    std::cout << x.first+1 << ' ' << x.second+1 << '\n';
  }

  return 0;
}

