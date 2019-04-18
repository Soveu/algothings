#include<iostream>
#include<utility>
#include<algorithm>
#include<stdint.h>

#define N 1000000

bool comp(uint8_t a, uint8_t b) {
  uint8_t afirst = a & 7;
  uint8_t bfirst = b & 7;

  if(afirst == bfirst) {
    return (a >> 3) < (b >> 3);
  }

  return afirst < bfirst;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  uint8_t domina[N];

  int n;
  std::cin >> n;

  for(int i=0; i<n; ++i) {
    short a, b;
    std::cin >> a >> b;
    domina[i] = (a & 7) | (b << 3);
  }

  std::sort(domina, domina+n, comp);

  uint8_t d = domina[0];
  short p = (d & 7);
  short k = (d >> 3);
  for(int i=1; i<n; ++i) {
    if((d >> 3) == (domina[i] & 7)) {
      d = domina[i];
    } else if((domina[i] >> 3) == (d >> 3)) {
      uint8_t _tmp = (domina[i] >> 3);
      domina[i] <<= 3;
      domina[i] |= _tmp;
      d = domina[i];
    } else {
      std::cout << "NIE\n";
      return 0;
    }
    
    k = (d >> 3);
  }

  std::cout << "TAK\n" << p << ' ' << k << '\n';

  return 0;
}

