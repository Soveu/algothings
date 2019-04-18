#include <iostream>
#include <vector>
#include <map>
#include <functional>

using Graph = std::vector<std::vector<int>>;

bool isCyclic(const Graph& g) {
  std::vector<bool> isVisited(g.size());

  std::function<bool(int, int)> dfs = [&](int v, int parent) {
    isVisited[v] = true;

    for(const auto child : g[v]) {
      if(child == parent) {
        continue;
      }
      if(isVisited[child] || dfs(child, v)) {
        return true;
      }
    }

    return false;
  };
  
  for(int i=1; i<g.size(); ++i) {
    if(!isVisited[i]) {
      if(dfs(i, -1)) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int x;
  std::cin >> x;

  for(int i=0; i<x; ++i) {
    int n, m;
    std::cin >> n >> m;

    Graph g(n+1);
    for(int i=0; i<m; ++i) {
      int a, b;
      std::cin >> a >> b;

      g[a].push_back(b);
      g[b].push_back(a);
    }

    std::cout << (isCyclic(g) ? "TAK\n" : "NIE\n");
  }

  return 0;
}

