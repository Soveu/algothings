#include <iostream>
#include <limits>
#include <utility>
#include <vector>
#include <set>
#include <stdint.h>

struct Edge {
  int to;
  int weight;
};

using Graph = std::vector<std::vector<Edge>>;

std::vector<int> dijkstra(const Graph& g, int source, int target) {
  std::vector<int64_t> distances(g.size(), std::numeric_limits<int64_t>::max());
  std::vector<int> prev(g.size());
  std::set<std::pair<int64_t, int>> activeVertices;

  distances[source] = 0;
  activeVertices.emplace(0, source);

  while(!activeVertices.empty()) {
    int where = activeVertices.begin()->second;
    if(where == target) {
      return prev;
    }

    activeVertices.erase(activeVertices.begin());

    for(const auto& edge : g[where]) {
      if(distances[edge.to] > distances[where] + edge.weight) {
        activeVertices.erase(std::make_pair(distances[edge.to], edge.to));
        distances[edge.to] = distances[where] + edge.weight;
        activeVertices.emplace(distances[edge.to], edge.to);
        prev[edge.to] = where;
      }
    }
  }

  return prev;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int noofnodes, noofedges;
  std::cin >> noofnodes >> noofedges;

  Graph g(noofnodes+1);
  for(int i=0; i<noofedges; ++i) {
    int from, to, weight;
    std::cin >> from >> to >> weight;
    g[from].push_back(Edge{to, weight});
    g[to].push_back(Edge{from, weight});
  }

  auto prev = dijkstra(g, 1, noofnodes);
  if(prev.size() == 0) {
    std::cout << "-1\n";
    return 0;
  }

  auto u = noofnodes;
  if(prev[u] == 0 && u != 1) {
    std::cout << "-1\n";
    return 0;
  }

  std::vector<int> ans;
  while(u != 0) {
    ans.push_back(u);
    u = prev[u];
  }
  
  if(ans.back() != 1) {
    std::cout << "-1\n";
    return 0;
  }

  for(auto it=ans.rbegin(); it != ans.rend(); ++it) {
    std::cout << *it << ' ';
  }
  std::cout << '\n';

  return 0;
}

