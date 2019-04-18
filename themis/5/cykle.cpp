#include<iostream>
#include<vector>
#include<set>

using Int = int;
using Graph = std::vector<std::set<int>>;

Graph g;
std::vector<bool> isVisited;

bool czy_cykliczny(size_t n) {
  isVisited[n] = true;

  for(const auto edge : g[n]) {
    if(edge == n) {
      g[n].erase(edge);
      continue;
    }
    if(!isVisited[edge]) {
      isVisited[edge] = true;
      g[edge].erase(n);
      g[n].erase(edge);
      if(czy_cykliczny(edge)) {
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

      g[a].insert(b);
      g[b].insert(a);
    }

    std::cout << (czy_cykliczny(1) ? "TAK\n" : "NIE\n");
  }

  return 0;
}

