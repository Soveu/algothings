#include<iostream>

using Int = long long int;

inline bool czyParzysta(Int x) {
  return (x & 1) == 0;
}

Int a(Int n) {
  if(n == 0) {
    return 2;
  }

  if(czyParzysta(n)) {
    Int x = a(n/2);
    return x*x;
  }

  return a(n-1);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  Int n;

  std::cin >> n;
  std::cout << a(n) << '\n';

  return 0;
}

