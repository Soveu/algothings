#include <iostream>

int d = 0;

bool f(int sum, int prev=0) {
  d += 1;
  std::cout << "d = " << d << ", sum = " << sum << ", prev = " << prev << '\n';
  if(sum == 0) {
    d -= 1;
    return true;
  }

  for(int i=prev+1; i<=sum; ++i) {
    if(f(sum-i, i)) {
      std::cout << "FOUND: " << i << '\n';
      if(d > 1) {
        d -= 1;
        return true;
      }
    }
  }

  d -= 1;
  return false;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;

  f(n);

  return 0;
}

