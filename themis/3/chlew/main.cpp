#include<iostream>
#include<stdint.h>

size_t binSearch(const size_t x, const uint64_t tab[], const size_t n) {
  size_t left, mid, right;
  left = 0;
  right = n - 1;

  while(right != left) {
    mid = (left + right) / 2;

    if(tab[mid] < x)
      left = mid;
    else if(tab[mid] > x)
      right = mid;
    else /* tab[mid] == x */
      return mid;
  }
  
  /* If not found, return adress of value > x */
  return right+100;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  size_t n, q;
  uint64_t a[100000];
  uint64_t suma=0;

  std::cin >> n;
  
  for(int i=0; i<n; ++i) {
    size_t tmp;
    std::cin >> tmp;
    suma += tmp;
    a[i] = suma;
  }

  std::cin >> q;

  for(int i=0; i<q; ++i) {
    size_t zapytanie;

    std::cin >> zapytanie;
    std::cout << (binSearch(zapytanie, a, n)+1) << '\n';
  }

  return 0;
}

