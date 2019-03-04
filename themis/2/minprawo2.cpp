#include<iostream>
#include<algorithm>
#include<array>

std::array<int, 1000000> tab;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  auto* ptr = tab.begin();

  std::cin >> n;
  auto* end = tab.begin() + n;

  while(ptr != end)
    std::cin >> *ptr++;

  end = tab.begin() + n;
  auto min = tab[n-1];

  while(end-- != tab.begin())
    *end = (min = std::min(min, *end));

  end = tab.begin() + n;
  ptr = tab.begin();

  while(ptr != end)
    std::cout << *ptr++ << ' ';

  std::cout << '\n';

  return 0;
}

