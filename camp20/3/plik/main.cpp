#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
  std::vector<int> neighbours;
  int value;
  int parent;
  int depth;
};

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n, a, b;
  std::cin >> n >> a >> b;
  a -= 1;
  b -= 1;

  Graph g(n);
  for(int i=1; i<n; ++i) {
    int u, v;
    std::cin >> u >> v;
    g[u-1].neighbours.push_back(v-1);
    g[v-1].neighbours.push_back(u-1);
  }

  g = set_root(std::move(g), a);
  const auto abpath = path_to_root(g, b);

  int a = 0;
  int b = abpath.size() / 2;
  int mid;

  while(a != b) {
    mid = (a+b) / 2;
  }

  return 0;
}

