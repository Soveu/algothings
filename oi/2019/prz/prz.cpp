#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define M 1000000007

struct Node {
  std::vector<int> friends;
  int x;
};

using Graph = std::vector<Node>;

bool by_x(const Node& a, const Node& b) {
  return a.x < b.x;
}

Graph prepare_graph(Graph g) {
  std::vector<bool> visited(g.size(), false);
  std::queue<int> queue;

  queue.push(0);
  while(!queue.empty()) {
    auto n = queue.front();
    queue.pop();
    visited[n] = true;

    int counter = 0;
    for(const int f : g[n].friends) {
      if(visited[f]) {
        continue;
      }

      queue.push(f);
      counter += 1;
    }

    g[n].x = counter;
  }

  return g;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n, m, z;
  std::cin >> n >> m >> z;

  Graph g(n);
  for(int i=0; i<m; ++i) {
    int a, b;
    std::cin >> a >> b;
    --a; --b;
    g[a].friends.push_back(b);
    g[b].friends.push_back(a);
  }

  g = prepare_graph(std::move(g));
  const auto maxRoot = std::max_element(g.begin(), g.end(), by_x)->x;

  for(int i=0; i<z; ++i) {
    int q;
    std::cin >> q;

    if(q <= maxRoot) {
      std::cout << "0\n";
      continue;
    }
    
    int64_t result = 1;
    for(const auto& node : g) {
      result *= (q - node.x);
      result %= M;
    }

    std::cout << result << '\n';
  }

  return 0;
}

