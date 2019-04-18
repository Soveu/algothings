#include<iostream>

using Int = long long int;

struct Coord {
  Int x, y;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  Int w, h, n;
  std::cin >> w >> h >> n;

  Coord czarne[20];
  for(Int i=0; i<n; ++i) {
    Int x, y;
    std::cin >> x >> y;
  }

  return 0;
}

