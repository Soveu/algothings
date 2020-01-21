#include<iostream>
#include<vector>

using Int = long long int;

struct Kwiatek {
  int x, y;
  int ilePodlewa = 0;
};

inline bool czy_podlewa(const Kwiatek& k, int xp, int yp, int rp) {
  return std::abs(k.x-xp) + std::abs(k.y-yp) <= rp;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int n, x, y, m;
  std::cin >> n >> m >> x >> y;

  std::vector<Kwiatek> vk(n);
  for(auto& k : vk) {
    std::cin >> k.x >> k.y;
  }

  for(int i=0; i<m; ++i) {
    int x, y, r;
    std::cin >> x >> y >> r;

    for(auto& k : vk) {
      if(czy_podlewa(k, x, y, r)) {
        k.ilePodlewa++;
      }
    }
  }

  for(const auto& k : vk) {
    std::cout << k.ilePodlewa << '\n';
  }

  return 0;
}

