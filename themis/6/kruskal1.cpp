#include <iostream>
#include <algorithm>
#include <vector>

struct Edge {
  int index;
  int from, to;
  int weight;
};

bool by_weight(const Edge& a, const Edge& b) {
  return a.weight < b.weight;
}

size_t repr[7000];

void init_repr(int n) {
  for(size_t i=0; i<=n; ++i) {
    repr[i] = i;
  }
}

size_t find(int x) {
  if(repr[x] == x) {
    return x;
  }

  repr[x] = find(repr[x]);

  return repr[x];
}

void join(int a, int b) {
  size_t reprOfa = find(a);
  size_t reprOfb = find(b);

  repr[reprOfa] = reprOfb;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;

  int i=0;
  std::vector<Edge> ve(m);
  for(auto& e : ve) {
    std::cin >> e.from >> e.to >> e.weight;
    e.index = ++i;
  }

  std::sort(ve.begin(), ve.end(), by_weight);
  init_repr(n);
  for(const auto& e : ve) {
    int a = find(e.from);
    int b = find(e.to);

    if(a == b) {
      continue;
    }

    std::cout << e.index << '\n';
    /* join */
    repr[a] = b;
  }

  return 0;
}

