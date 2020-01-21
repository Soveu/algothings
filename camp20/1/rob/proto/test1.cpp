#include <iostream>
#include <set>

struct Range {
  int begin;
  int end;
};
bool operator<(const Range& a, const Range& b) {
  return a.end < b.end;
}

using RangeMap = std::set<Range>;

std::ostream& operator<<(std::ostream& out, const Range& r) {
  out << '<' << r.begin << ", " << r.end << '>';
  return out;
}
std::ostream& operator<<(std::ostream& out, const RangeMap& rm) {
  out << '{';
  for(const auto& kv : rm) {
    out << kv << ", ";
  }
  out << '}';
  return out;
}

RangeMap remove_range(RangeMap rm, Range r) {
  if(rm.size() == 0) {
    return rm;
  }

  /* WARNING: ranges are sorted by their __end__ */
  auto it = rm.lower_bound({0, r.begin});

  if(it == rm.end()) {
    /* Not found any */
    return rm;
  }
  if(it->begin >= r.end) {
    /* These ranges don't overlap and there is a 'hole' */
    return rm;
  }

  auto item = *it;
  auto tail = rm.lower_bound({0, r.end});
  if(tail != rm.end() && tail->end == r.end) {
    ++tail;
  }
  tail = rm.erase(it, tail);

  /* Because of pointer invalidation we need to do it here */
  if(tail != rm.end() && tail->begin < r.end) {
    auto t = *tail;
    rm.erase(tail);
    if(t.end > r.end) {
      rm.insert({r.end, t.end});
    }
  }
  if(item.begin < r.begin) {
    rm.insert({
      item.begin, 
      std::min(r.begin, item.end)
    });
  }

  return rm;
}

int main() {
  RangeMap rm{
    {0, 9},
    {12, 13}
  };
  Range r{8, 13};

  rm = remove_range(std::move(rm), r);
  std::cout << rm << '\n';

  return 0;
}

