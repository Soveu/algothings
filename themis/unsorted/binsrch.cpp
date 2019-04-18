#include <iostream>

int tab[1000000];

size_t binsrch(int left, int right, const int item) {
  int mid;

  while(left < right) {
    mid = (left + right) / 2;

    if(tab[mid] < item) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  return right;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;

  for(int i=0; i<n; ++i) {
    std::cin >> tab[i];
  }

  int m;
  std::cin >> m;

  for(int i=0; i<m; ++i) {
    int x;
    std::cin >> x;
    std::cout << (n - binsrch(0, n, x)) << ' ';
  }

  std::cout << '\n';
  return 0;
}

