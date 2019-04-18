#include <iostream>
#include <vector>
#include <cmath>

struct Edge {
  int to;
  double distance;
};

struct Position {
  int x, y;
};

struct Node {
  std::vector<Edge> adjecantNodes;
  Position pos;
};

using Graph = std::vector<Node>;

double distance(const Position a, const Position b) {
  int x = std::abs(a.x - b.x);
  int y = std::abs(a.y - b.y);

  return std::sqrt(x*x + y*y);
}

double shortest_jump(const Graph& g) {
  std::vector<bool> isPath(g.size());

  std::function<double(int)> dfs = [&](int v) {
    isPath[v] = true;

    for(const auto child : g) {
      if(isPath[child]) {
        continue;
      }
    }

    isPath[v] = false;
  }

}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;

  Graph g(n);
  for(auto& n : g) {
    std::cin >> n.pos.x >> n.pos.y;
  }

  for(int i=0; i<n; ++i) {
    for(int j=i+1; j<n; ++j) {
      double d = distance(g[i].pos, g[j].pos);
      g[i].adjecantNodes[j].distance = d;
      g[j].adjecantNodes[i].distance = d;
    }
  }

  std::cout << shortest_jump(g) << '\n';

  return 0;
}

