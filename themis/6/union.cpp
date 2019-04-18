#include <iostream>
#include <vector>

size_t repr[300000];

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

  int n, m, q;
  std::cin >> n >> m >> q;

  init_repr(n);

  for(int i=0; i<m; ++i) {
    int a, b;
    std::cin >> a >> b;

    join(a, b);
  }

  for(int i=0; i<q; ++i) {
    int w, a, b;
    std::cin >> w >> a >> b;

    if(w == 0) {
      std::cout << (find(a) == find(b) ? "TAK\n" : "NIE\n");
    } else {
      join(a, b);
    }
  }

  return 0;
}

