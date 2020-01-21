#include <iostream>
#include <map>
#include <set>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;

  for(int i=0; i<t; ++i) {
    int n;
    std::cin >> n;

    std::set<std::pair<int, int>> segments;
    std::map<int, int> axis;

    for(int j=0; j<n; ++j) {
      std::pair<int, int> p;
      std::cin >> p.first >> p.second;
      segment.insert(p);
      if(axis.count(p.second) == 0) {
        axis[p.first] = -1;
      } else {
        axis[p.first] -= 1;
      }
      if(axis.count(p.first) == 0) {
        axis[p.first] = 1;
      } else {
        axis[p.first] += 1;
      }
    }

    std::vector<int> lowPoints;
    auto it = axis.begin();
    int32_t heightLeft = *it; ++it;
    int32_t height = *it; ++it;
    int32_t heightRight = *it; ++it;
    while(it != axis.end()) {
      if(height == 1 && (heightLeft > 1 || heightRight > 1)) {
        lowPoints.push_back(kv.first);
      }
      ++it;
    }

    std::cout << counter << '\n';
  }
}

