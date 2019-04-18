#include<iostream>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;

  if(n < 3) {
    std::cout << "NIE\n";
    return 0;
  }

  int max;
  std::cin >> max;
  n -= 1;

  long long suma = 0;
  for(int i=0; i<n; ++i) {
    int x;
    std::cin >> x;

    if(max < x) {
      suma += max;
      max = x;
    } else {
      suma += x;
    }
  }

  std::cout << (suma > max ? "TAK\n" : "NIE\n");

  return 0;
}

