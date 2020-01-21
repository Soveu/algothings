#include <iostream>
#include <stdint.h>

#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cmath>

#define DEBUG_PRINT(x) (x)

std::vector<std::pair<int, int>> ans(int from, int to, int side, std::vector<std::pair<int, int>> v) {
  int range = to - from;

  if(range <= 4) {
    for(int i=from; i<to; ++i) {
      v.push_back({i, i+i});
    }
  }

  range /= 3;

  v = ans(from, from+range, 1, std::move(v));
  v = ans(from + range+1, from + 2*range, 2, std::move(v));
  v = ans(from + 2*range+1, to, 3, std::move(v));

  return v;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n, subtask;
  std::cin >> n;

  return 0;
}

