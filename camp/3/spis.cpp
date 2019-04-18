#include<iostream>
#include<set>
#include<string>

using Int = long long int;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::set<std::string> a;
  std::string s;

  std::cin >> n >> m;
  for(int i=0; i<n; ++i) {
    std::cin >> s;
    a.insert(std::move(s));
  }
  for(int i=0; i<m; ++i) {
    std::cin >> s;
    auto item = a.find(s);
    if(item != a.end()) {
      a.erase(s);
    }
  }

  for(const auto& x : a) {
    std::cout << x << '\n';
  }

  return 0;
}

