#include <iostream>
#include <string>

#define P 32
#define M 1000000007

using Int = long long;

int pw[200000];

int get_hash(const std::string& s) {
  int res = 0;

  for(size_t i=0; i<s.size(); ++i) {
    res += ((Int)(s[s.size()-i-1] & 0x1f) * pw[i]) % M;
    res %= M;
  }

  return res;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  /* init the modulo powers of P array */
  Int _res = 1;
  pw[0] = 1;
  for(size_t i=1; i<200000; ++i) {
    _res *= P;
    _res %= M;
    pw[i] = _res;
  }

  int n, wynik=0;
  std::cin >> n;

  std::string s;
  std::cin >> s;

  Int hash_original = get_hash(s);

  for(int i=1; i<n; ++i) {
    Int hash;
    std::cin >> s;
    hash = get_hash(s);

    Int cycled_hash = hash_original;
    for(size_t i=0; i<s.size(); ++i) {
      if(cycled_hash == hash) {
        wynik++;
        break;
      }

      cycled_hash -= ((Int)(s[i] & 0x1f) * pw[s.size()-1]) % M;
      if(cycled_hash < 0) {
        cycled_hash += M;
      }
      cycled_hash *= P;
      cycled_hash %= M;
      cycled_hash += ((Int)(s[i] & 0x1f)) % M;
      cycled_hash %= M;
    }
  }

  std::cout << wynik << '\n';

  return 0;
}

