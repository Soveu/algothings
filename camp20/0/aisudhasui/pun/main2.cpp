#include <vector>
#include <unordered_map>

#include <iostream>
#include <stdint.h>
#include <cmath>

struct Point {
  int32_t x, y;

  bool operator==(const Point& p) const {
    return this->x == p.x && this->y == p.y;
  }
};

struct PointHasher {
  uint64_t operator()(const Point& p) const noexcept {
    const int64_t magic = 11400714819323197441ULL;
    return p.x * magic + p.y * magic;
  }
};

int64_t pow2(int32_t x) {
  return x*x;
}

int64_t distance_square(const Point& a, const Point& b) {
  return pow2(a.x - b.x) + pow2(a.y - b.y);
}

int32_t sign(int32_t x) {
  return (x < 0 ? -1 : 1);
}

using ChunkMap = std::unordered_map<Point, std::vector<Point>, PointHasher>;

int calc_points(const ChunkMap& map, Point chunk1, Point chunk2, int64_t chunkSize) {
  auto it1 = map.find(chunk1);
  auto it2 = map.find(chunk2);

  if(it1 == map.end() || it2 == map.end()) {
    return 0;
  }

  int counter = 0;
  for(const auto& p1 : it1->second) {
    for(const auto& p2 : it2->second) {
      counter += (distance_square(p1, p2) == chunkSize);
    }
  }

  return counter;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int64_t n, k;
  std::cin >> n >> k;
  
  ChunkMap map;
  for(int i=0; i<n; ++i) {
    Point p;
    std::cin >> p.x >> p.y;
    
    Point chunk{
      sign(p.x) + p.x / k, 
      sign(p.y) + p.y / k
    };
    map[chunk].push_back(p);
  }

  int counter = 0;
  for(const auto& kv : map) {
    const Point chunk = kv.first;

    for(int a=-1; a<=1; ++a) {
      for(int b=-1; b<=1; ++b) {
        auto chunk2 = chunk;
        chunk2.x += a;
        chunk2.y += b;
        counter += calc_points(map, chunk, chunk2, k);
      }
    }
  }

  std::cout << (counter / 2) << '\n';

  return 0;
}

