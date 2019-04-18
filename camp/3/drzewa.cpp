#include<iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  std::vector<int> g[2][100000];

  int n, m;
  std::cin >> n >> m;

  for(int j=0; j<2; ++j) {
    for(int i=1; i<n; ++i) {
      int a, b;
      std::cin >> a >> b;

      g[j][a].push_back(b);
      g[j][b].push_back(a);
    }
  }

  return 0;
}

