#include<iostream>

using Graph = std::vector<std::vector<int>>;

Graph g;
std::vector<char> v;
int height, width, k;

bool crawl_down(const int w, const int h);
bool crawl_right(const int w, const int h);

bool crawl_down(const int w, const int h) {
  for(int i=h+1; i<height; ++i) {
    auto& x= v[i*width + w];

    if(w == width && h == height) {
      return true;
    }

    if(x != '.') {
      return crawl_down(i, h) || crawl_right(i, h);
    }
  }

  return false;
}

bool crawl_right(const int w, const int h) {
  for(int i=w+1; i<width; ++i) {
    auto& x= v[h*width + i];

    if(w == width && h == height) {
      return true;
    }

    if(x != '.') {
      return crawl_down(i, h) || crawl_right(i, h);
    }
  }

  return false;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  std::cin >> height >> width >> k;

  v.resize(height * width);
  for(int i=0; i<height; ++i) {
    std::cin >> (v.data() + i*width);
  }

  /* TODO: what if there is something at (0, 0) ?? */
  crawl_down(0, 0);

  return 0;
}

