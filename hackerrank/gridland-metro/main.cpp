#include <iostream>
#include <vector>

struct Range {
  int begin, end;
};

std::vector<Range> remove_range(std::vector<Range> ranges, Range r) {
  return ranges;
}

int64_t gridlandMetro(int n, int m, int k, vector<array<int, 3>> track) {
  std::unordered_map<int, std::vector<Range>> map;
  for(const auto& x : track) {
    auto row = x[0];
    auto begin = x[1];
    auto end = x[2];

    auto it = map.find(row);
    if(it == map.end()) {
      map[row] = std::vector<Range>{{0, n}};
      it = map.find(row);
    }

    *it = remove_range(std::move(*it), {begin, end});
  }

  int64_t sum = 0;
  for(const auto& ranges : map) {
    sum += calc_ranges_span(ranges);
  }

  return n * (m - map.size()) + sum;
}

