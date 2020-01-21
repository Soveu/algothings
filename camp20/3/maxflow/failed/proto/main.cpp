#include <iostream>
#include <stdint.h>

#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <cmath>

#define DEBUG_PRINT(x) (x)

struct Node {
  std::vector<int> neighbours;
  int flow;
};

using Graph = std::vector<Node>;

Graph bfs(Graph g, int begin, int end, int amount) {
  std::vector<bool> visited(g.size());
  std::queue<int> q;

  q.push(begin);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    visited[u] = true;
    g[u].flow += amount;

    for(const auto& n : g[u].neighbours) {
      if(!visited[n]) {
        q.push(n);
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

  Graph g(n);
  for(int i=1; i<n; ++i) {
    int u, v;
    std::cin >> u >> v;
    g[u-1].neighbours.push_back(v-1);
    g[v-1].neighbours.push_back(u-1);
  }

  std::unordered_map<uint32_t, int> pumps;
  for(int i=0; i<k; ++i) {
    uint32_t u, v;
    std::cin >> u >> v;
    u -= 1;
    v -= 1;
    if(u < v) {
      std::swap(u, v);
    }

    uint32_t val = (u << 16) | (v);
    auto it = pumps.find(val);
    if(it == pumps.end()) {
      pumps[val] = 1;
    } else {
      it->second += 1;
    }
  }

  for(const auto& kv : pumps) {
    int pump = kv.first;
    g = bfs(std::move(g), (pump >> 16), (pump & 0xffff), kv.second);
  }

  int max = 0;
  for(const auto& node : g) {
    max = std::max(node.flow, max);
  }

  std::cout << max-1 << '\n';

  return 0;
}

