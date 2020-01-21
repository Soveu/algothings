#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdint.h>

#define DEBUG(x) (x)

using Range = std::pair<int, int>;
using RangeMap = std::map<int, int>;

std::ostream& operator<<(std::ostream& out, const RangeMap& rm) {
  out << '{';
  for(const auto& kv : rm) {
    out << '<' << kv.first << ", " << kv.second << ">, ";
  }
  out << "}\n";
  return out;
}

RangeMap remove_range(RangeMap rm, Range r) {
  if(rm.size() == 0) {
    return rm;
  }

  auto item = rm.lower_bound(r.first);
  if(item == rm.end()) {
    --item;
    if(item->second <= r.first) {
      /* Nothing to do */
      return rm;
    }
    // else
    item->second = r.first;
    return rm;
  }

  auto end = rm.lower_bound(r.second); // TODO check
  --end;

  if(item == rm.begin()) {
  }

  return rm;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n, h;
  std::cin >> n >> h;

  int counter = 0;
  RangeMap visible;
  Range r;

  std::cin >> r.first >> r.second;
  visible[0] = h;
  visible = remove_range(std::move(visible), r);
  counter += 2;

  std::cout << DEBUG(visible);
  for(int i=1; i<n; ++i) {
    std::cin >> r.first >> r.second;
    visible = remove_range(std::move(visible), r);
    std::cout << DEBUG(visible);

    if(visible.size() == 0) {
      counter += 2;
      visible[0] = h;
      visible = remove_range(std::move(visible), r);
      std::cout << DEBUG(visible);
    }

    std::cout << DEBUG("----------------\n");
  }

  std::cout << DEBUG("counter=") << counter << '\n';

  return 0;
}

