#include<iostream>
#include<array>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  static std::array<ssize_t, 1000000> tab;

  size_t  n, przewaga=0, licznik=0;
  ssize_t lider;

  std::cin >> n;
  const auto* end = tab.begin() + n;

  for(auto* it = tab.begin(); it != end; ++it) {
    ssize_t tmp;
    std::cin >> tmp;

    if (lider == tmp)
      przewaga++;
    else if (przewaga == 0)
      lider = tmp;
    else
      przewaga--;

    *it = tmp;
  }

  for(auto* it = tab.begin(); it != end; ++it) {
    if (lider == *it)
      licznik++;
  }
  
  if (licznik > n/2)
    std::cout << lider;
  else
    std::cout << "NIE MA LIDERA";

  std::cout << '\n';

  return 0;
}

