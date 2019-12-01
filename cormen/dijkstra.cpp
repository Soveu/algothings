#include <iostream>
#include <limits>
#include <utility>
#include <vector>
#include <set>

/*
struct edge { int to, length; };
    
int dijkstra(const vector< vector<edge> > &graph, int source, int target) {
    vector<int> min_distance( graph.size(), INT_MAX );
    min_distance[ source ] = 0;
    set< pair<int,int> > active_vertices;
    active_vertices.insert( {0,source} );
        
    while (!active_vertices.empty()) {
        int where = active_vertices.begin()->second;
        if (where == target) return min_distance[where];
        active_vertices.erase( active_vertices.begin() );
        for (auto ed : graph[where]) 
            if (min_distance[ed.to] > min_distance[where] + ed.length) {
                active_vertices.erase( { min_distance[ed.to], ed.to } );
                min_distance[ed.to] = min_distance[where] + ed.length;
                active_vertices.insert( { min_distance[ed.to], ed.to } );
            }
    }
    return INT_MAX;
}
*/

struct Edge {
  int to;
  int weight;
};

using Graph = std::vector<std::vector<Edge>>;

int dijkstra(const Graph& g, int source, int target) {
  std::vector<int> distances(g.size(), std::numeric_limits<int>::max());
  std::set<std::pair<int, int>> activeVertices;

  distances[source] = 0;
  activeVertices.emplace(0, source);

  while(!activeVertices.empty()) {
    int where = activeVertices.begin()->second;
    if(where == target) {
      return distances[where];
    }

    activeVertices.erase(activeVertices.begin());

    for(const auto& edge : g[where]) {
      if(distances[edge.to] > distances[where] + edge.weight) {
        activeVertices.erase(std::make_pair(distances[edge.to], edge.to));
        distances[edge.to] = distances[where] + edge.weight;
        activeVertices.emplace(distances[edge.to], edge.to);
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

  Graph g(noofnodes);
  for(int i=0; i<noofedges; ++i) {
    int from, to, weight;
    std::cin >> from >> to >> weight;
    g[from].push_back(Edge{to, weight});
    g[to].push_back(Edge{from, weight});
  }

  std::cout << dijkstra(g, 0, noofnodes-1) << '\n';
  return 0;
}

