#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

struct Point {
  int x, y;
};

using Rectangle = std::array<Point, 2>;

struct RectArray {
  Rectangle rects[4];
  int size;
  
  void push(const Rectangle& r) {
    assert(this->size < 4);
    this->rects[this->size] = r;
    this->size += 1;
  }
};

void remove_zeroes(std::vector<RecArray>& rav) {
  int start = 0;
  int end = rav.size() - 1;

  while(start < end) {
    while(start < end && rav[start].size != 0) ++start;
    while(start < end && rav[end].size != 0) --end;
    rav[start] = rav[end];
  }

  rav.resize(start-0);
}

/*
 * 1. x e <p[0].x; p[1].x>
 *    y e <p[0].y; p[1].y>
 *
 * 2. x e <p[0].x; p[1].x>
 *    y e <0; p[0].y> u <p[1].y; Y>
 *
 * 3. x e <0; p[0].x> u <p[1].x; X>
 *    y e <p[0].y; p[1].y>
 *
 * 4. x e <0; p[0].x> u <p[1].x; X>
 *    y e <0; p[0].y> u <p[1].y; Y>
 */

std::array<Rectangle, 2> gen_case2(const Rectangle r, const Point mapsize) {
  return std::array<Rectangle, 2>{
    Rectangle{Point{r[0].x, 0}, Point{r[1].x, r[0].y}},
    Rectangle{Point{r[0].x, r[1].y}, Point{r[1].x, mapsize.y}}
  };
}

std::array<Rectangle, 2> gen_case3(const Rectangle r, const Point mapsize) {
  return std::array<Rectangle, 2>{
    Rectangle{Point{0, r[0].y}, Point{r[0].x, r[1].y}},
    Rectangle{Point{r[1].x, r[0].y}, Point{mapsize.x, r[1].y}}
  };
}

std::array<Rectangle, 4> gen_case3(const Rectangle r, const Point mapsize) {
  return std::array<Rectangle, 4>{
    Rectangle{Point{0; 0}     , Point{r[0].x, r[0].y}},
    Rectangle{Point{0, r[1].y}, Point{r[0].x, mapsize.y}}
    Rectangle{Point{r[1].x, 0}, Point{mapsize.x, r[0].y}},
    Rectangle{Point{r[1].x, r[1].y}, Point{mapsize.x, mapsize.y}}
  };
}

std::array<int, 2> common_line(int ax1, int ax2, int bx1, int bx2) {
  auto x1 = std::max(ax1, bx1);
  auto x2 = std::min(ax2, bx2);
  return std::array<int, 2>{x1,x2};
}

Rectangle common_rect(const Rectangle& a, const Rectangle& b) {

}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);
  
  Point mapsize;
  int n;
  std::cin >> n >> mapsize.x >> mapsize.y;

  for(int i=0; i<n; ++i) {
    Rectangle r;
    std::cin >> r[0].x >> r[0].y >> r[1].x >> r[1].y;
    r = normalize(r);
  }

  return 0;
}

