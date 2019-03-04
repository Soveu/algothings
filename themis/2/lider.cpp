#include<iostream>
#include<vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  size_t  n, przewaga=0;
  ssize_t lider;
  std::vector<ssize_t> tab;

  std::cin >> n;
  tab.resize(n);

  for(auto& x : tab)
    std::cin >> x;

  for(const auto x : tab) {
    if (x == lider)
      przewaga++;
    else if (przewaga == 0)
      lider = x;
    else
      przewaga--;
  }

  size_t count = 0;
  for(const auto x : tab) {
    if (x == lider)
      count++;
  }

  if (count > tab.size()/2)
    std::cout << lider;
  else
    std::cout << "NIE MA LIDERA";

  std::cout << '\n';

  return 0;
}

