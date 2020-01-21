/* Marx Tomasz */

#include <iostream>
#include <stdint.h>

#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cmath>

#define DEBUG_PRINT(x) (x)

bool is_correct(const std::vector<char>& v) {
  char col = v[0];
  for(int i=1; i<v.size(); ++i) {
    if(col == v[i]) {
      return false;
    }
    col = v[i];
  }

  return true;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;

  std::vector<char> cockroaches(n);
  std::cin >> cockroaches.data();
  
  int blackCounter = 0;
  int redCounter = 0;
  for(char c : cockroaches) {
    blackCounter += (c == 'b');
    redCounter += (c == 'r');
  }

  if(std::abs(blackCounter - redCounter) <= 1 && is_correct(cockroaches)) {
    std::cout << "0\n";
    return 0;
  }
  if(blackCounter == 0) {
    std::cout << redCounter/2 << '\n';
    return 0;
  }
  if(redCounter == 0) {
    std::cout << blackCounter/2 << '\n';
    return 0;
  }

  return 0;
}

