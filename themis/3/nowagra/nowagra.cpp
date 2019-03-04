#include<iostream>
#include<stdint.h>

#define RESZKA  'R'
#define ORZEL   'O'
#define MOD     1000000007

/*
void flip(uint64_t x, bool gra[], const uint64_t n) {
  while(x <= n)
    gra[x] = !gra[x];
}
*/

uint64_t calcMod(uint64_t n) {
  uint64_t mnoznik=1;
  
  if(n==0)
    return 1;

  for(uint64_t i=0; i<n; ++i) {
    mnoznik *= 2;
    mnoznik %= MOD;
  }

  return mnoznik;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  bool gra[100001]{false};
  uint64_t n, suma=0;
  char tmp;

  std::cin >> n;

  for(uint64_t i=0; i<n; ++i) {
    std::cin >> tmp;
    gra[i] = (tmp == RESZKA);
  }

  for(uint64_t i=0; i<n; ++i){
    if(gra[n-i-1]) {
      suma += calcMod(i);
      suma %= MOD;
    }    
  }

  std::cout << suma << '\n';

  return 0;
}

