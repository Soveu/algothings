#include<iostream>
#include<algorithm>
#include<array>
#include<vector>

std::array<int, 1000000> tab;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  size_t n;
  std::vector<int> tab;

  std::cin >> n;
  tab.resize(n);

  for(auto& x : tab)
    std::cin >> x;

  auto min = tab.back();

  for(auto it = tab.rbegin(); it != tab.rend(); ++it)
    *it = (min = std::min(min, *it));

  for(const auto x : tab)
    std::cout << x << ' ';

  std::cout << '\n';

  return 0;
}

