#include <iostream>
#include <limits>
#include <utility>
#include <vector>
#include <set>

struct Edge {
  int to;
  int weight;
};

using Graph = std::vector<std::vector<Edge>>;

int dijkstra(const Graph& g, int source, int target) {
  std::vector<int> distances(g.size(), std::numeric_limits<int>::max());
  std::vector<int> prev(g.size());
  std::set<std::pair<int, int>> activeVertices;

  distances[source] = 0;
  activeVertices.emplace(0, source);

  while(!activeVertices.empty()) {
    int where = activeVertices.begin()->second;
    if(where == target) {
      for(const auto& x : prev) {
        std::cout << x << ' ';
      }
      std::cout << std::endl;
      return distances[where];
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

  return std::numeric_limits<int>::max();
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

  std::cout << dijkstra(g, 1, noofnodes) << '\n';
  return 0;
}

