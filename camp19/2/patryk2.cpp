#include<iostream>
#include<utility>
#include<vector>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  std::vector<std::pair<int, int>> stack;

  int n;
  std::cin >> n;

  int h;
  std::cin >> h;
  stack.emplace_back(h, 0);

  int wynik = 0;
  for(int i=1; i<n; ++i) {
    std::cin >> h;

    if(stack.back().first == h) {
      wynik += stack.back().second; // <-------------------+
      stack.back().second += 1; //                         |
    } else {//                                             |
      while(!stack.empty() && stack.back().first < h) {//  |
        wynik += stack.back().second; //                   |
        stack.pop_back(); //                               |
      } //                                                 |

      stack.emplace_back(h, 1); //                         |
    }//                                                    |

    if(!stack.empty()) { //                                |
      wynik += 1; // <--- HERE LIES THE BUG----------------+
    }
  }

  std::cout << wynik << '\n';

  return 0;
}

