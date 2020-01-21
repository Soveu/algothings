#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
  std::vector<int> neighbours;
  int value;
  int parent;
};

using Graph = std::vector<Node>;

Graph set_root(Graph g, int root) {
  std::vector<int> stack;

  stack.push_back(root);
  while(!stack.empty()) {
    int u = stack.back();
    stack.pop_back();

    for(const auto n : g[u].neighbours) {
      if(n != g[u].parent) {
        stack.push_back(n);
        g[n].parent = u;
      }
    }
  }

  return g;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n, k;
  std::cin >> n >> k;

  Graph g(n+1);
  for(int i=1; i<n; ++i) {
    int u, v;
    std::cin >> u >> v;
    g[u].neighbours.push_back(v);
    g[v].neighbours.push_back(u);
  }

  g[0].neighbours.push_back(1);
  g = set_root(std::move(g), 0);

  for(int i=0; i<k; ++i) {
    int u, v;
    std::cin >> u >> v;
  }

  return 0;
}

