#include <iostream>
#include <vector>
#include <queue>

using Graph = std::vector<std::vector<int>>;

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;

  std::vector<std::pair<int, int>> right, left;
  for(int i=0; i<m; ++i) {
    std::pair<int, int> e;
    std::cin >> e.first >> e.second;
    if(e.first < e.second) {
      right.push_back(e);
    } else {
      left.push_back(e);
    }
  }

  const auto& res = (right.size() < left.size() ? right : left);
  std::cout << res.size() << '\n';
  for(const auto& kv : res) {
    std::cout << kv.first << ' ' << kv.second << '\n';
  }

  return 0;
}

