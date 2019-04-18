#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#include <stdint.h>

struct Position { int x, int y };

struct Edge {
  int from, int to;
  int64_t weight;
};

struct DisjoinSet {
  struct Item {
    int repr;
    int count;
  };

  std::vector<Item> vi;

  void init(size_t n) {
    this->vi.resize(n);
    size_t i=0;
    for(auto& x : this->vi) {
      x.repr = ++i;
      x.count = 1;
    }
  }

  int find(int x) {
    if(this->vi[x].repr == x) {
      return x;
    }

    return this->vi[x].repr = find(this->vi[x].repr);
  }

  void join(int _a, int _b) {
    Item* a = &(this->vi[this->find(_a)]);
    Item* b = &(this->vi[this->find(_b)]);

    if(a->count > b->count) {
      b->repr = a->repr;
      a->count += b->count;
    } else {
      a->repr = b->repr;
      b->count += a->count;
    }
  }
};

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::vector<Position> vp(n);
  for(auto* p : vp) {
    std::cin >> p->x >> p->y;
  }

  std::vector<Edge> ve;
  ve.reserve(n*n/2);

  for(int i=0; i<n; ++i) {
    for(int j=i+1; j<n; ++j) {
      int64_t x = std::abs(vp[i].x - vp[j].x);
      int64_t y = std::abs(vp[i].y - vp[j].y);
      ve.push_back(i, j, x*x+y*y);
    }
  }

  std::sort(ve.begin(), ve.end(), [](const Edge& a, const Edge& b) {
    return a.weight < b.weight;
  });

  DisjoinSet ds;
  ds.init(n);
  for(const auto& e : ve) {
    int a = ds.find(e.from);
    int b = ds.find(e.to);

    if(a + b == 1) {
      std::cout << std::sqrt(e.weight) << '\n';
      return 0;
    }

    ds.join(a, b);
  }

  std::cout << std::sqrt(ve.back().weight) << '\n';
  return 0;
}

