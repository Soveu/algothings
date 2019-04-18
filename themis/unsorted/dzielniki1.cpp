#include <iostream>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int k;
  std::cin >> k;

  int r = 1;
  int aktualnyDzielnik = 1;
  int potega = 0;
  for(int i=0; i<k; ++i) {
    int x;
    std::cin >> x;

    if(x == aktualnyDzielnik) {
      potega += 1;
    } else {
      r *= (potega + 1);
      potega = 1;
      aktualnyDzielnik = x;
    }
  }
  
  r *= (potega + 1);

  std::cout << r << '\n';
  return 0;
}

