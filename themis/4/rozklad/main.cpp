#include<iostream>
#include<cmath>

using Int = long long int;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  Int n, m;

  std::cin >> n;
  m = n;

  for(Int i=2; i*i<=n; ++i) {
    while(m % i == 0) {
      m /= i;
      std::cout << i << ' ';
    }
  }

  if(m * m >= n)
    std::cout << m;

  std::cout << '\n';
  
  return 0;
}

