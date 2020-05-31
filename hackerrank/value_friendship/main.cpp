#include <iostream>
#include <vector>
#include <deque>
#include <stdint.h>

using Graph = std::vector<std::vector<int>>;

int64_t bfs(const Graph& g, std::vector<bool>* visited, int node) {
  int64_t ret = 0;
  std::deque<int> q;

  q.push_back(node);
  (*visited)[node] = true;
  ret += 1;

  while(!q.empty()) {
    int u = q.front(); q.pop_front();

    for(const auto& v : g[u]) {
      if(!(*visited)[v]) {
        q.push_back(v);
        (*visited)[v] = true;
        ret += 1;
      }
    }
  }

  return ret;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int q;
  std::cin >> q;

  for(int i=0; i<q; ++i) {
    int64_t result = 0;
    
    int n, m;
    std::cin >> n >> m;

    Graph g(n);

    for(int j=0; j<m; ++j) {
      int u, v;
      std::cin >> u >> v;
      g[u-1].push_back(v-1);
      g[v-1].push_back(u-1);
    }

    std::vector<bool> visited(n);
    for(int j=0; j<n; ++j) {
      if(visited[j]) continue;
      auto x = bfs(g, &visited, j);
      result += x * (x-1);
      /* 0*1 + 1*2 + 2*3 + 3*4 + 4*5 ... */
    }

    std::cout << result << '\n';
  }

  return 0;
}

