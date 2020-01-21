#include <iostream>
#include <stdint.h>

#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cmath>

#define DEBUG_PRINT(x) (x)

const int BASE = 4;

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n, subtask;
  std::cin >> n;

  std::vector<std::pair<int, int>> answer;
  answer.reserve(5*n);

  for(int i=1; i<=n; ++i) {
    for(int dist=1; dist+i<=n; dist *= BASE) {
      answer.push_back({i, i+dist});
      answer.push_back({i+dist, i});
    }
  }

  std::cout << answer.size() << '\n';
  for(const auto& kv : answer) {
    std::cout << kv.first << ' ' << kv.second << '\n';
  }

  return 0;
}

