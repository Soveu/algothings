#include <iostream>
#include <vector>
#include <stdint.h>

bool has_non_positive_prefix(const std::vector<int32_t>& v) {
  int64_t sum = 0;
  for(int i=0; i<v.size(); ++i) {
    sum += v[i];
    if(sum <= 0) return true;
  }

  return false;
}

bool has_non_positive_suffix(const std::vector<int32_t>& v) {
  int64_t sum = 0;
  for(int i=v.size()-1; i>=0; --i) {
    sum += v[i];
    if(sum <= 0) return true;
  }

  return false;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;

  for(int i=0; i<t; ++i) {
    int n;
    std::cin >> n;
    std::vector<int32_t> cupcakes(n);
    for(auto& x : cupcakes) {
      std::cin >> x;
    }
    if(has_non_positive_prefix(cupcakes) || has_non_positive_suffix(cupcakes)) {
      std::cout << "NO\n";
    } else {
      std::cout << "YES\n";
    }
  }
}

