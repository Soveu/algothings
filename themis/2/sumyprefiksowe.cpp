#include<iostream>

int main() {
  int tmp;
  int i;
  int sum=0;

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  for(std::cin >> i; i > 0; --i) {
    std::cin >> tmp;
    sum += tmp;
    std::cout << sum << ' ';
  }

  std::cout << '\n';

  return 0;
}

