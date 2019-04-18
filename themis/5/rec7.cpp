#include<iostream>

using Int = long long int;

Int d(Int n) {
  if(n == 0) {
    return 1;
  }

  if(n % 3 == 0) {
    return d(n-1) + d(n-2);
  }
  /* else */
  return d(n-1) * 2;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  Int n;
  std::cin >> n;
  std::cout << d(n) << '\n';

  return 0;
}

