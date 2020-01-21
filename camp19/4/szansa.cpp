#include<iostream>
#include<set>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n, k;
  std::cin >> n >> k;

  /* co nie działa? */
  std::set<long long> liczby;
  for(int i=n; i>0; --i) {
    for(int j=n; j>=i; --j) {
      liczby.insert((long long)i*j);
      if(liczby.size() == k) {
        goto finish;
      }
    }
  }

finish:
  auto it = liczby.rbegin();
  while(it != liczby.rend()) {
    std::cout << *it << '\n';
    ++it;
  }

  return 0;
}

