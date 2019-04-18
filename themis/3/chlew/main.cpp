#include<iostream>
#include<stdint.h>

size_t binSearch(const uint64_t x, const uint64_t tab[], const size_t n) {
  size_t left, mid, right;
  left = 0;
  right = n - 1;

  while(left < right) {
    mid = (left + right) / 2;
    
    if(tab[mid] < x)
      left = mid+1;
    else
      right = mid;
  }

  return left;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  size_t n;
  static uint64_t a[100001];
  uint64_t q, suma=0;

  std::cin >> n;
  
  for(size_t i=0; i<n; ++i) {
    uint64_t tmp;
    std::cin >> tmp;
    suma += tmp;
    a[i] = suma;
  }

  std::cin >> q;

  for(uint64_t i=0; i<q; ++i) {
    uint64_t zapytanie;

    std::cin >> zapytanie;
    std::cout << (binSearch(zapytanie, a, n)+1) << '\n';
  }

  return 0;
}

