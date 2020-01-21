#include <iostream>
#include <stdint.h>

#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cmath>

#define DEBUG(x) (x)

using Iterator = std::vector<int>::iterator;

bool is_median(Iterator it, const Iterator end, const int value) {
  const size_t dist = std::distance(it, end);
  size_t less = 0;
  size_t more = 0;

  while(it != end) {
    less += (*it < value);
    more += (*it > value);
    ++it;
  }

  return (
    (less < dist/2) &&
    (dist > dist/2 + more)
  );
}

/* [10,20,30] */
bool is_valid(std::vector<int>& orig, const int value) {
  for(int len=1; len<=orig.size(); ++len) {
    auto begin = orig.begin();
    auto end = begin + len;

    while(end != orig.end()) {
      if(!is_median(begin, end, value)) {
        return false;
      }

      ++begin;
      ++end;
    }
  }

  return true;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;

  std::vector<int> orig(n);
  for(auto& x : orig) {
    std::cin >> x;
  }
  
  std::vector<int> copy = orig;
  std::sort(copy.begin(), copy.end());
  for(int i=copy.size()/2; i<copy.size(); ++i) {
    DEBUG(std::cout << "validating " << copy[i] << '\n');
    if(is_valid(orig, copy[i])) {
      std::cout << copy[i] << '\n';
      return 0;
    }
  }

  std::cout << "SCREAMFORHELP";
  return 1;
}

