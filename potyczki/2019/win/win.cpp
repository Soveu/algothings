#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int height, bottlesNeeded;
  std::cin >> height >> bottlesNeeded;

  int bottlesToTake = 1;
  while(bottlesToTake < bottlesNeeded) {
    for(int i=0; i<bottlesToTake; ++i) {
      int tmp; std::cin >> tmp;
    }
    bottlesNeeded -= bottlesToTake;
    bottlesToTake += 1;
  }

  int minYear = std::numeric_limits<int>::max();
  for(int i=0; i<bottlesToTake; ++i) {
    int x;
    std::cin >> x;
    
    minYear = std::min(minYear, x);
  }

  std::cout << minYear << '\n';

  return 0;
}

