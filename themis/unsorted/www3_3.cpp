#include <iostream>
#include <vector>
#include <functional>

using Graph = std::vector<std::vector<int>>;

std::vector<int> dfs(const Graph& g) {
  std::vector<int> count(g.size(), 1);

  std::function<int(int)> _dfs = [&](int v) {
    for(const auto child : g[v]) {
      count[v] += _dfs(child);
    }

    return count[v];
  };

  _dfs(1);

  return count;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;

  Graph g(n+1);
  for(int i=1; i<n; ++i) {
    int a, b;
    std::cin >> a >> b;
    
    g[a].push_back(b);
  }

  std::vector<int> count = std::move(dfs(g));

  int q;
  std::cin >> q;
  for(int i=0; i<q; ++i) {
    int x;
    std::cin >> x;
    std::cout << count[x] << '\n';
  }

  return 0;
}
