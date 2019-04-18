#include<iostream>

using Int = long long int;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  
  int height, width, k;
  std::cin >> height >> width >> k;

  std::vector<char> v(height * width);
  std::vector<int>  score(height * width);
  for(int i=0; i<height; ++i) {
    std::cin >> (v.data() + i*width);
  }

  score[0] = k;
  if(v[0] != '.') {
    //propagate k/2
    for(int i=1; i<height; ++i) {
      score[i*width + 0] = k/2;
    }
    for(int i=1; i<width; ++i) {
      score[i] = k/2;
    }
  }

  for(int i=1; i<height; ++i) {
    score[i*width + 0] = k;
  }
  
  //TODO: look for

  return 0;
}

