#include <iostream>
#include <vector>
#include <array>
#include <stdint.h>

using Graph = std::vector<std::array<int, 4>>;

int n, m;
char data[51][51];

Graph build_graph() {
  Graph g(n*m);

  for(int y=0; y<n; ++y) {
    for(int x=0; x<m; ++x) {
      if(data[y][x] == '.' || data[y][x] == '*') {
        g[y*m + x];
      }
    }
  }

  return g;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  std::cin >> n >> m;

  for(int i=0; i<n; ++i) {
    std::cin >> data[i];
  }

  Graph g = build_graph();

  return 0;
}

