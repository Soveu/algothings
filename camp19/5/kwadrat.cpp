#include<iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  int potegi = 0;
  for(const auto prime : primes) {
    if(prime > n) {
      break;
    }
    potegi += n / prime;
  }

  return 0;
}

