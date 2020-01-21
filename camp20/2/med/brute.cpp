#include <iostream>
#include <stdint.h>

#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cmath>

#define DEBUG_PRINT(x) (x)

std::ostream& operator<<(std::ostream& out, const std::vector<int>& v) {
  out << '[';
  for(const auto& x : v) {
    out << x << ", ";
  }
  return out << ']';
}

std::vector<int> medians_len(
  std::vector<int> medians, 
  const std::vector<int>& numbers,
  int len)
{
  auto end = numbers.begin() + len-1;
  auto start = numbers.begin();

  while(end != numbers.end()) {
    std::vector<int> tmp(start, end+1);
    auto med = tmp.begin() + (tmp.size()/2);
    std::nth_element(tmp.begin(), med, tmp.end());
    medians.push_back(*med); 

    ++start;
    ++end;
  }

  return medians;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;

  std::vector<int> v(n);
  for(auto& x : v) {
    std::cin >> x;
  }

  std::vector<int> medians;
  for(int i=1; i<=n; ++i) {
    medians = medians_len(std::move(medians), v, i);
  }
  std::cout << DEBUG_PRINT(medians) << DEBUG_PRINT('\n');

  std::sort(medians.begin(), medians.end());
  std::cout << medians[medians.size()/2] << '\n';

  return 0;
}

