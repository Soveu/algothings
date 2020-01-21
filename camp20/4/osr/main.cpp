#include <iostream>
#include <stdint.h>

#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cmath>

#define DEBUG_PRINT(x) (x)

int16_t field[1001][1001];
int32_t sum[1001][1001];

int calc_sum(int x, int y, int d) {
  int ans = 0;

  for(int i=0; i<d; ++i) {
    for(int j=0; j<=i; ++j) {
      ans += field[y+i][x+j];
    }
  }

  return ans;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;

  for(int y=0; y<n; ++y) {
    for(int x=0; x<n; ++x) {
      std::cin >> field[y][x];
    }
  }

  int q;
  std::cin >> q;
  for(int i=0; i<q; ++i) {
  int x, y, d;
    std::cin >> x >> y >> d;
    std::cout << calc_sum(x, y, d) << '\n';
  }

  return 0;
}

