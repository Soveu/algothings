#include <iostream>
#include <vector>

struct Ant {
  int position;
  int direction;
};

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;

  std::vector<Ant> ants(n);
  for(auto& ant : ants) {
    std::cin >> ant.position >> ant.direction;
  }

  std::sort(ants.begin(), ants.end(), [](const Ant& a, const Ant& b) {
    return a.position < b.position;
  });

  return 0;
}

