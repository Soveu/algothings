#include<iostream>
#include<stdint.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  static bool czyByla[1000001]{false};
  uint64_t n, tmp, ans=0;

  std::cin >> n;

  for(uint64_t i=0; i<n; ++i) {
    std::cin >> tmp;

    if(tmp > n) {
      ++ans;
      continue;
    }

    if(czyByla[tmp])
      ++ans;
    else
      czyByla[tmp] = true;
  }

  std::cout << ans << '\n';

  return 0;
}



