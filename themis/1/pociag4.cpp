#include<iostream>

#define DEBUGPRINT                      \
  for(size_t i=1; i<6; ++i){  \
    std::cout << osobowe[i] << ' ';     \
  }                                     \
  std::cout << '\n';                    \

int main() {
  size_t przedzialy, tmp, wynik=0;
  int osobowe[6]{0};

  std::cin >> przedzialy;

  for(size_t i=0; i<przedzialy; ++i){
    std::cin >> tmp;
    osobowe[tmp]++;
  }

  DEBUGPRINT;

  osobowe[5] += osobowe[4];
  osobowe[1] -= osobowe[4];
  osobowe[4] = 0;

  DEBUGPRINT;

  osobowe[5] += osobowe[3];
  osobowe[2] -= osobowe[3];
  osobowe[3] = 0;

  DEBUGPRINT;
}


