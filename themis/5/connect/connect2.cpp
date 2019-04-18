#include<iostream>
#include<vector>

using Int = int;
using Graph = std::vector<std::vector<int>>;

Graph g;
std::vector<bool> isVisited;

void crawl(size_t n) {
  isVisited[n] = true;

  for(const auto edge : g[n]) {
    if(!isVisited[edge]) {
      isVisited[edge] = true;
      crawl(edge);
    }
  }
}

bool czy_spojny() {
  for(size_t i=1; i<isVisited.size(); ++i) {
    if(!isVisited[i])
      return false;
  }

  return true;
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
    }

    crawl(1);
    std::cout << (czy_spojny() ? "TAK\n" : "NIE\n");
  }

  return 0;
}

