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

std::vector<int> dijkstra(const Graph& g, int source) {
  std::vector<int> distances(g.size(), std::numeric_limits<int>::max());
  std::set<std::pair<int, int>> activeVertices;

  distances[source] = 0;
  activeVertices.emplace(0, source);

  while(!activeVertices.empty()) {
    int where = activeVertices.begin()->second;

    activeVertices.erase(activeVertices.begin());

    for(const auto& edge : g[where]) {
      if(distances[edge.to] > distances[where] + edge.weight) {
        activeVertices.erase(std::make_pair(distances[edge.to], edge.to));
        distances[edge.to] = distances[where] + edge.weight;
        activeVertices.emplace(distances[edge.to], edge.to);
      }
    }
  }

  return distances;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;

  for(int i=0; i<t; ++i) {
    int noofnodes, noofedges;
    std::cin >> noofnodes >> noofedges;

    Graph g(noofnodes);
    for(int i=0; i<noofedges; ++i) {
      int from, to, weight;
      std::cin >> from >> to >> weight;

      from -= 1;
      to -= 1;

      g[from].push_back(Edge{to, weight});
      g[to].push_back(Edge{from, weight});
    }

    int s;
    std::cin >> s;
    s -= 1;

    const auto res = dijkstra(g, s);
    for(int i=0; i<res.size(); ++i) {
      if(i == s) {
        continue;
      }
      std::cout << (res[i] == std::numeric_limits<int>::max() ? -1 : res[i]);
      std::cout << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}

