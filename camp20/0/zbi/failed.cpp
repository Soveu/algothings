#include <iostream>
#include <vector>
#include <unordered_set>

using Graph = std::vector<std::unordered_set<int>>;

size_t highest_size_index(const Graph& g) {
  size_t ret = 0;
  size_t max = g[0].size();
  for(size_t i=1; i<g.size(); ++i) {
    if(g[i].size() > max) {
      ret = i;
      max = g[i].size();
    }
  }
  return ret;
}

void debug_print(const Graph& g) {
  for(const auto& node : g) {
    for(const auto& to : node) {
      std::cout << to << ' ';
    }
    std::cout << '\n';
  }

  std::cout << "------------------\n";
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;

  Graph g(n);

  for(int i=0; i<m; ++i) {
    int u, v;
    std::cin >> u >> v;
    u -= 1;
    v -= 1;
    g[u].insert(v);
    g[v].insert(u);
  }

  int counter = 0;
  while(g.size() > 1) {
    size_t i = highest_size_index(g);
    if(g[i].size() == 0) {
      break;
    }
    for(const auto& v : g[i]) {
      g[v].erase(i);
    }
    g[i].clear();
    counter += 1;
  }

  std::cout << (n-counter) << '\n';

  return 0;
}

