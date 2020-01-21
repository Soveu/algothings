#include<iostream>
#include<vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int height, width, k;
  std::cin >> height >> width >> k;

  std::vector<char> v;
  v.resize(height * width);

  for(int i=0; i<height; ++i) {
    std::cin >> (v.data() + i*width);
  }

  int ileKulek = 0;
  for(int i=0; i<k; ++i) {
    int w = 0;
    int h = 0;
    char kierunek = 'D';

    while(h < height && w < width) {
      auto& pole = v[h*width + w];

      switch(pole) {
        case 'D':
          kierunek = 'D';
          pole = 'P';
          break;
        case 'P':
          kierunek = 'P';
          pole = 'D';
          break;
      }

      if(kierunek == 'D') {
        h++;
      } else {
        w++;
      }

      if(w == width-1 && h == height-1 && kierunek == 'P') {
        ileKulek++;
      }
    }
  }

  std::cout << ileKulek << '\n';
}

