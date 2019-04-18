#include <iostream>
#include <vector>

struct Node {
  std::vector<int> neighbours;
};

using Graph = std::vector<Node>;
Graph g;

int dfs(int v) {
  int count = 1;

  for(const auto child : g[v].neighbours) {
    count += dfs(child);
  }

  return count;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;

  g.resize(n+1);
  for(int i=1; i<n; ++i) {
    int a, b;
    std::cin >> a >> b;

    g[a].neighbours.push_back(b);
  }

  int q;
  std::cin >> q;

  for(int i=0; i<q; ++i) {
    int x;
    std::cin >> x;
    std::cout << dfs(x) << '\n';
  }

  return 0;
}

