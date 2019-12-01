#include <iostream>
#include <stdint.h>

int64_t calc_fuel(int64_t mass) {
  return (mass / 3) - 2;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int32_t sum = 0;
  int x;
  while(std::cin >> x) {
    auto additionalFuel = calc_fuel(x);
    sum += additionalFuel;
    while(additionalFuel > 6) {
      additionalFuel = calc_fuel(additionalFuel);
      sum += additionalFuel;
    }
  }

  std::cout << sum << '\n';
  return 0;
}

