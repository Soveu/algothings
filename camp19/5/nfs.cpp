#include<iostream>
#include<vector>

struct Node {
  std::vector<int> neighbours;
  bool visited = false;
  int pre = 0;
  int low = 0;
};

using Graph = std::vector<Node>;

Graph g;
int tick;

void dfs(int v, int parent) {
  g[v].visited = true;
  g[v].pre = tick;
  tick++;
  g[v].low = g[v].pre;

  for(const auto child : g[v].neighbours) {
    if(child == parent) {
      continue;
    }

    if(g[child].visited) {
      g[v].low = std::min(g[v].low, g[child].pre);
    } else {
      dfs(child, v);
      g[v].low = std::min(g[v].low, g[child].low);
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;

  g.resize(n);
  tick = 1;

  for(int i=0; i<m; ++i) {
    int a, b;
    std::cin >> a >> b;
    --a; --b;

    g[a].neighbours.push_back(b);
    g[b].neighbours.push_back(a);
  }

  dfs(0, -1);

  for(const auto& node : g) {
    std::cout << node.pre << ", " << node.low << '\n';
  }

  return 0;
}

