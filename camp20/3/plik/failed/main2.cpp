#include <iostream>
#include <stdint.h>

#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cmath>

#define DEBUG_PRINT(x) (x)

using Graph = std::vector<std::vector<int>>;

struct Pair {
  int vertex;
  int i;
};

int64_t bfs(const Graph& g, int a, int b) {
  std::vector<bool> visited(g.size());
  std::vector<Pair> queues[2];
  int64_t counter = 0;

  queues[0].push_back({a, 0});
  queues[0].push_back({b, 0});
  visited[a] = true;
  visited[b] = true;

  int queueNumber = 0;
  while(!queues[0].empty() || !queues[1].empty()) {
    for(auto u : queues[queueNumber]) {
      while(u.i < g[u.vertex].size() && visited[g[u.vertex][u.i]]) {
        u.i += 1;
      }

      if(u.i < g[u.vertex].size()) {
        queues[1-queueNumber].push_back({u.vertex, u.i});
        int v = g[u.vertex][u.i];
        visited[v] = true;
        queues[1-queueNumber].push_back({v, 0});
      }
    }

    queues[queueNumber].clear();
    queueNumber = 1 - queueNumber;
    counter += 1;
  }

  return counter-1;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);
  
  int n, a, b;
  std::cin >> n >> a >> b;

  Graph g(n);
  for(int i=1; i<n; ++i) {
    int u, v;
    std::cin >> u >> v;
    g[u-1].push_back(v-1);
    g[v-1].push_back(u-1);
  }

  std::cout << bfs(g, a-1, b-1) << '\n';

  return 0;
}

