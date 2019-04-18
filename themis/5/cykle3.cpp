#include<iostream>
#include<vector>

using Int = int;
using Graph = std::vector<std::vector<int>>;

Graph g;
std::vector<bool> isVisited;

bool czy_cykliczny(size_t n=1, size_t parent=1) {
  isVisited[n] = true;

  for(const auto edge : g[n]) {
    if(edge == n || edge == parent) {
      continue;
    }
    if(!isVisited[edge]) {
      isVisited[edge] = true;
      if(czy_cykliczny(edge, n)) {
        return true;
      }
    } else {
      return true;
    }
  }

  return false;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  Int zestawy;
  std::cin >> zestawy;

  for(Int i=0; i<zestawy; ++i) {
    Int n, m;
    std::cin >> n >> m;

    isVisited.clear();
    isVisited.resize(n+1);
    g.clear();
    g.resize(n+1);
    for(Int j=0; j<m; ++j) {
      Int a, b;
      std::cin >> a >> b;

      g[a].push_back(b);
      g[b].push_back(a);
    }

    std::cout << (czy_cykliczny() ? "TAK\n" : "NIE\n");
  }

  return 0;
}

