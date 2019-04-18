#include<iostream>
#include<utility>
#include<vector>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  std::vector<std::pair<int, int>> stack;

  int n;
  std::cin >> n;

  int h;
  std::cin >> h;
  stack.emplace_back(h, 1);

  long long ans = 0;
  std::pair<int, int> p;
  for(int i=1; i<n; ++i) {
    std::cin >> p.first;
    p.second = 1;

    while(!stack.empty() && stack.back().first <= p.first) {
      auto prev = stack.back();
      ans += prev.second;
      stack.pop_back();

      if(prev.first == p.first) {
        p.second += prev.second;
      }
    }

    if(!stack.empty()) {
      ans += 1;
    }
    stack.push_back(p);
  }

  std::cout << ans << '\n';

  return 0;
}

