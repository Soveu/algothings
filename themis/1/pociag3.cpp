#include<iostream>

#define DEBUG 1
#define TAXISIZE 5
#define TAXIARRSIZE (TAXISIZE+1)

#define DEBUGPRINT                      \
  for(size_t i=1; i<TAXIARRSIZE; ++i){  \
    std::cout << osobowe[i] << ' ';     \
  }                                     \
  std::cout << '\n';                    \

void mv (size_t, size_t, size_t*);
void mv2(size_t, size_t, size_t*);

int main() {
  size_t przedzialy, tmp, wynik=0;
  size_t osobowe[TAXIARRSIZE] = {0};

  std::cin >> przedzialy;

  for(size_t i=0; i<przedzialy; ++i){
    std::cin >> tmp;
    osobowe[tmp]++;
  }

  #ifdef DEBUG
  DEBUGPRINT;
  #endif

  mv(1,4,osobowe);
  mv(2,3,osobowe);

  if(osobowe[1] != 0 && osobowe[3] != 0) {
    mv2(1, 3, osobowe);
  }

  return 0;
}

void mv2(size_t a, size_t b, size_t* osobowe){
  auto const x = (5 - b);
  auto t = osobowe[a] / x;
  auto r = osobowe[a] % x;

  osobowe[5] += t;
  osobowe[b] -= t;
  osobowe[a] -= t * x;
  
  mv(a, b, osobowe);

  #ifdef DEBUG
  DEBUGPRINT;
  #endif
}

void mv(size_t a, size_t b, size_t* osobowe){
  /* a + b -> a+b */
  if(osobowe[a] < osobowe[b]){
    osobowe[a+b] += osobowe[a];
    osobowe[b] -= osobowe[a];
    osobowe[a] = 0;
  } else {
    osobowe[a+b] += osobowe[b];
    osobowe[a] -= osobowe[b];
    osobowe[b] = 0;
  }

  #ifdef DEBUG
  DEBUGPRINT;
  #endif

  return;
}

