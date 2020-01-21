#include<iostream>

#define N 7

struct Node {
  bool isConnected[N];
  bool isEven;
  bool isVisited;
};

Node g[N];
//---------------
bool czyPolaczony[N][N];
bool czyParzysty[N];
bool czyOdwiedzony[N];

void dfs(int x) {
  czyOdwiedzony[x] = true;
  for(int i=1; i<N; ++i) {
    if(czyPolaczony[x][i] && !czyOdwiedzony[i]) {
      dfs(i);
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  for(int i=0; i<n; ++i) {
    int a, b;
    std::cin >> a >> b;

    czyPolaczony[a][b] = true;
    czyPolaczony[b][a] = true;

    czyParzysty[a] = !czyParzysty[a];
    czyParzysty[b] = !czyParzysty[b];
  }

  int start = 0;
  for(int i=1; i<7; ++i) {
    for(int j=1; j<7; ++j) {
      if(czyPolaczony[i][j]) {
        start = i;
        goto foundstart;
      }
    }
  }

foundstart:
  dfs(start);
  int sum = 0;
  for(int i=1; i<N; ++i) {
    sum += czyOdwiedzony[i];
  }
  if(sum == 0) {
    std::cout << "NIEE\n";
    return 0;
  }

  sum = 0;
  int p, k;
  for(int i=1; i<N; ++i) {
    if(czyParzysty[i]) {
      sum += 1;

      if(sum == 1) {
        p = i;
      } else if(sum == 2) {
        k = i;
      }
    }
  }

  if(sum == 0 || sum == 2) {
    std::cout << "TAK\n" << p << ' ' << k << '\n';
  } else {
    std::cout << "NIEEEE\n";
  }

  return 0;
}

