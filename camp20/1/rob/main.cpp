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

bool by_end(const std::pair<int, int>& p, const int x) {
  return p.second < x;
}

RangeMap remove_range(RangeMap rm, Range r) {
  if(rm.size() == 0) {
    return rm;
  }

  auto item = rm.lower_bound(r.first);

  if(item != rm.begin() && (item == rm.end() || item->first > r.first)) {
    --item;
  }

  if(item->first == r.first && item->second > r.second) {
    /* shorten from front */
    auto t = *item;
    rm.erase(item);
    rm[r.second] = t.second;
    return rm;
  }
  if(item->first < r.first && item->second == r.second) {
    /* shorten from back */
    item->second = r.first;
    return rm;
  }
  if(item->first < r.first && item->second > r.second) {
    /* split */
    auto t = *item;
    item->second = r.first;
    rm[r.second] = t.second;
    return rm;
  }

  if(item->first < r.first) {
    item->second = std::min(item->second, r.first);
    ++item;
  }

  /* TODO change for binsearch */
  auto end = rm.lower_bound(r.second, by_end);
  /* auto end = item;
  while(end != rm.end() && end->second <= r.second) {
    ++end;
  }
  */

  if(end != rm.end() && r.second > end->first) {
    auto t = *end;
    rm.erase(item, end);
    rm[r.second] = t.second;
    return rm;
  }

  rm.erase(item, end);
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

