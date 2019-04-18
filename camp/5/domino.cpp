#include<iostream>
#include<utility>
#include<algorithm>

#define N 1000000

using Domino = std::pair<char, char>;

bool comp_first(const Domino& a, const Domino& b) {
  if(a.first == b.first) {
    return a.second < b.second;
  }

  return a.first < b.first;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  Domino domina[N];

  int n;
  std::cin >> n;

  for(int i=0; i<n; ++i) {
    std::cin >> domina[i].first >> domina[i].second;
  }

  std::sort(domina, domina+n, comp_first);

  // DEBUG
  /*
  for(int i=0; i<n; ++i) {
    std::cout << domina[i].first << ' ' << domina[i].second << '\n';
  }
  */

  Domino d = domina[0];
  char p = d.first;
  char k = d.first;
  for(int i=1; i<n; ++i) {
    if(d.second == domina[i].first) {
      d = domina[i];
    } else if(domina[i].second == d.second) {
      std::swap(domina[i].second, domina[i].first);
      d = domina[i];
    } else {
      std::cout << "NIE\n";
      return 0;
    }

    k = d.second;
  }

  std::cout << "TAK\n" << p << ' ' << k << '\n';

  return 0;
}

