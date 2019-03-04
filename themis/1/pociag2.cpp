#include<iostream>

#define DEBUG 1
#define TAXISIZE 5
#define TAXIARRSIZE (TAXISIZE+1)

bool mv(size_t, size_t, size_t*);

int main() {
  size_t przedzialy, tmp, wynik=0;
  size_t osobowe[TAXIARRSIZE] = {0};
  bool any[TAXIARRSIZE] = {0};

  std::cin >> przedzialy;

  for(size_t i=0; i<przedzialy; ++i){
    std::cin >> tmp;
    osobowe[tmp]++;
  }

  #ifdef DEBUG
  for(size_t i=1; i<TAXIARRSIZE; ++i){
    std::cout << osobowe[i] << ' ';
  }
  std::cout << '\n';
  #endif

  any[1] = mv(1, 4, osobowe);
  any[2] = mv(2, 3, osobowe);
  any[3] = !any[2];
  any[4] = !any[1];

  if(!any[1] && !any[2]) goto winner;

  if(any[1]){
    any[1] = !(any[3] ? 
        any[3] = !mv(1, 3, osobowe) : 
        any[2] = !mv(1, 2, osobowe));

    if(any[1] && any[3]) {
      mv(1, 3, osobowe);
    } else if(any[2] && any[3]){
      mv(2, 3, osobowe);
    } else if(any[1] && any[4]){
      mv(1, 4, osobowe);
    }
  }

  return 0;
}

bool mv(size_t a, size_t b, size_t* osobowe){
  /* a + b -> a+b */
  bool flag = (osobowe[a] < osobowe[b]);

  if(flag){
    osobowe[a+b] += osobowe[a];
    osobowe[b] -= osobowe[a];
    osobowe[a] = 0;
  } else {
    osobowe[a+b] += osobowe[b];
    osobowe[a] -= osobowe[b];
    osobowe[b] = 0;
  }

  #ifdef DEBUG
  for(size_t i=1; i<TAXIARRSIZE; ++i){
    std::cout << osobowe[i] << ' ';
  }
  std::cout << '\n';
  #endif

  return !flag;
}

