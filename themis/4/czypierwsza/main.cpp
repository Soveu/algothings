#include<iostream>
#include<cmath>

using Int = long long int;

bool czyPierwsza(Int n) {
  for(int i = std::sqrt(n); i > 1; --i) {
    if(n % i == 0)
      return false;
  }

  return true;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  Int n;

  std::cin >> n;
  std::cout << (czyPierwsza(n) ? "pierwsza\n" : "zlozona\n");

  return 0;
}

