#include<iostream>
#include<vector>

struct Edge {
  int weight;
  int node;
};

using Graph = std::vector<std::vector<Edge>>;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  Graph g(n);
  for(auto& node : g) {
    w.resize(n);

    for(auto& edge : node) {
      std::cin >> edge;
    }
  }

  for(int i=0; i<n; ++i) {
    int x;
    std::cin >> x;
  }

  return 0;
}

