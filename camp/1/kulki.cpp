/* zrobić graf przełączników
 * dfs'em usunąć liście (oprócz końca i początku)
 */
#include<iostream>
#include<vector>
#include<iomanip>

using Int = long long int;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  Int height, width, k;
  std::cin >> height >> width >> k;

  std::vector<char> v;
  v.resize(height * width);

  for(Int i=0; i<height; ++i) {
    std::cin >> (v.data() + i*width);
  }

  Int n = 0;
  for(Int i=0; i<k; ++i) {
    Int w = width, h = height;
    auto it = v.begin();
    char kierunek = 'D';
    while(h >= 0 && w >= 0) {
      /*
      std::cout << "h = " << h << '\n'
        << "w = " << w << '\n'
        << "kierunek = " << kierunek << '\n'
        << "*it = " << *it << "\n\n";
        */
      switch(*it) {
        case 'D':
          *it = 'P';
          it += width;
          kierunek = 'D';
          --h;
          break;
        case 'P':
          *it = 'D';
          it += 1;
          kierunek = 'P';
          --w;
          break;
        default:
          if(kierunek == 'P') {
            it += 1;
            --w;
          }
          else {
            it += width;
            --h;
          }
      }
    }

//    std::cout << w << ' ' << h << (w+h == -1 ? " WIN\n" : "\n");
    if(w+h == -1) {
      ++n;
    }
  }

  std::cout << n << '\n';

  return 0;
}

