#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

struct Bottle {
  int year;
  int getCost;
};

bool by_year(const Bottle& a, const Bottle& b) {
  return a.year < b.year;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int height, bottlesNeeded;
  std::cin >> height >> bottlesNeeded;
  Bottle bestBottle{std::numeric_limits<int>::max(), std::numeric_limits<int>::max()};

  for(int layer=1; layer <= height && bottlesNeeded >= layer; ++layer) {
    for(int width=0; width < layer; ++width) {
      Bottle b;
      b.getCost = (layer - width) * (1 + width);
      std::cin >> b.year;

      if(b.getCost <= bottlesNeeded) {
        bestBottle = std::min(bestBottle, b, by_year);
      }
    }
  }

  std::cout << bestBottle.year << '\n';

  return 0;
}

