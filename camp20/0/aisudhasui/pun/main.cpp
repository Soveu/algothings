#include <iostream>
#include <vector>
#include <stdint.h>
#include <cmath>

struct Point {
  int32_t x, y;
};

int64_t pow2(int32_t x) {
  return x*x;
}

int64_t distance_square(const Point& a, const Point& b) {
  return pow2(a.x - b.x) + pow2(a.y - b.y);
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int64_t n, k;
  std::cin >> n >> k;

  std::vector<Point> vp(n);
  for(auto& point : vp) {
    std::cin >> point.x >> point.y;
  }

  int64_t counter = 0;
  for(auto it1 = vp.begin(); it1 != vp.end(); ++it1) {
    for(auto it2 = it1+1; it2 != vp.end(); ++it2) {
      counter += (distance_square(*it1, *it2) == k);
    }
  }

  std::cout << counter << '\n';

  return 0;
}

