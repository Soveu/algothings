#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stdint.h>

std::set<int> create_set(int n) {
  std::vector<int> x;
  for(int i=-n; i<0; ++i) {
    x.push_back(i);
  }
  for(int i=1; i<n; ++i) {
    x.push_back(i);
  }

  return std::set<int>(x.begin(), x.end());
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);
  
  int n;
  std::cin >> n;

  std::vector<char> relations(n-1);
  std::cin >> relations.data();

  std::set<int> nonUsedNumbers = create_set(n);
  std::vector<int> perm;
  perm.reserve(n);

  int number = 0;
  perm.push_back(0);
  for(int i=0; i<n-1; ++i) {
    auto it = nonUsedNumbers.upper_bound(number);
    if(relations[i] == '>') {
      --it;
    }

    number = *it;
    nonUsedNumbers.erase(it);
    perm.push_back(number);
  }

  int offset = 1 - *std::min_element(perm.begin(), perm.end());

  for(const auto& x : perm) {
    std::cout << (x+offset) << ' ';
  }
  std::cout << '\n';

  return 0;
}

