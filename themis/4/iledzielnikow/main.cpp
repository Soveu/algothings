#include<iostream>
#include<cmath>

using Int = long long int;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  Int n, i;
  double sqrt;
  int liczbaDzielnikow=0;

  std::cin >> n;
  sqrt = std::sqrt(n);

  for(i=1; i<sqrt; ++i) {
    if(n % i == 0)
      liczbaDzielnikow += 2;
  }

  if(i == sqrt)
    liczbaDzielnikow += 1;

  std::cout << liczbaDzielnikow << '\n';

  return 0;
}

