#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stdint.h>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);
  
  int n;
  std::cin >> n;

  n -= 1;
  std::vector<char> relations(n);
  std::cin >> relations.data();

  std::set<int> usedNumbers;
  std::vector<int> perm;
  perm.reserve(n+1);
  int number = 0;

  perm.push_back(0);
  usedNumbers.insert(0);
  for(int i=0; i<n; ++i) {
    do {
      number += (relations[i] == '>' ? -1 : 1);
    } while(usedNumbers.find(number) != usedNumbers.end());

    usedNumbers.insert(number);
    perm.push_back(number);
  }

  int offset = 1 - *std::min_element(perm.begin(), perm.end());

  for(const auto& x : perm) {
    std::cout << (x+offset) << ' ';
  }
  std::cout << '\n';

  return 0;
}

