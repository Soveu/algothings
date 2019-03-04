#include<iostream>

int t[100000];

int main() {
  int n,m,l,p,x;

  std::cin >> n >> m;

  for(int i=0; i<m; i++){
    std::cin >> l >> p >> x;

    for(int j=l; l<p; j++){
      t[j] = x;
    }
  }

  for(int i=0; i<n; i++){
    std::cout << t[i] << ' ';
  }

  std::cout << '\n';

  return 0;
}

