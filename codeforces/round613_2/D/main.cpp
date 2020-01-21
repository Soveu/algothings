#include <iostream>
#include <vector>
#include <stdint.h>
#include <limits>
#include <algorithm>

uint32_t next_bit(uint32_t x) {
  uint32_t ret = 1;
  while(x != 0) {
    x >>= 1;
    ret <<= 1;
  }
  return ret;
}

uint32_t brute(const std::vector<uint32_t>& v, uint32_t maxx) {
  uint32_t min = std::numeric_limits<uint32_t>::max();
  for(uint32_t x=0; x != maxx; ++x) {
    uint32_t max = std::numeric_limits<uint32_t>::min();
    for(const auto val : v) {
      max = std::max(max, val ^ x);
    }
    min = std::min(min, max);
  }

  return min;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::vector<uint32_t> v(n);
  for(auto& x : v) {
    std::cin >> x;
  }

  std::cout << brute(v, next_bit(*std::max_element(v.begin(), v.end()))) << '\n';
}

