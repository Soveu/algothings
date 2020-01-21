#include <iostream>
#include <stdint.h>

int64_t gcd(int64_t a, int64_t b) {
  while(b != 0) {
    int64_t c = a % b;
    a = b;
    b = c;
  }

  return a;
}

int64_t lcm(int64_t a, int64_t b) {
  return a * (b / gcd(a, b));
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int64_t x;
  std::cin >> x;

  int64_t ans = 0;
  for(int64_t i=1; i*i <= x; ++i) {
    if(x % i == 0 && lcm(i, x/i) == x) {
      ans = i;
    }
  }

  std::cout << ans << ' ' << (x/ans) << '\n';
}

