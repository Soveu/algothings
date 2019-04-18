#include <iostream>
#include <vector>

struct Item {
  int sum;
  int prev;
};

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;

  std::vector<Item> stack;
  stack.push_back(Item{n, 0});

  for(int i=1; i<=n; ++i) {
    stack.push_back(Item{stack.back().sum-i, i});

    if(stack.back().sum <= stack.back().prev) {
      stack.back().prev += stack.back().sum;
      stack.back().sum = 0;
    }
    if(stack.back().sum == 0) {
      auto it = stack.begin() + 1;
      auto end = stack.end();

      while(it != end) {
        std::cout << (it->prev) << ' ';
        ++it;
      }
      std::cout << '\n';

      stack.pop_back();
      stack.back().sum -= 1;
      stack.back().prev += 1;
      i = stack.back().prev;
    }
  }

  return 0;
}

