#include <vector>
#include <iostream>
#include <algorithm>

std::vector<int> climbingLeaderboard(std::vector<int> scores, const std::vector<int>& alice) {
    std::vector<int> res(alice.size());
    scores.erase(std::unique(scores.begin(), scores.end()), scores.end());

    for(const auto& x : scores) {
      std::cout << x << ' ';
    }
    std::cout << '\n';

    for(int i=0; i<alice.size(); ++i) {
        res[i] = std::distance(
            scores.rend(), 
            std::upper_bound(scores.rbegin(), scores.rend(), alice[i])
        );
        res[i] = 1 - res[i];
    }

    return res;
}

int main() {
  auto res = climbingLeaderboard(
      {100, 100, 50, 40, 40, 20, 10}, 
      {5, 25, 50, 120}
  );

  for(const auto& x : res) {
    std::cout << x << ' ';
  }
  std::cout << '\n';

  return 0;
}

