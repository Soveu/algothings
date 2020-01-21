#include<iostream>
#include<vector>

#define M 1000000033

using Int = long long int;
using Uint = unsigned long long int;

std::vector<int> _t;
std::vector<Uint> _sum;

int t(ssize_t n) {
  if(n <= 0) {
    return 0;
  }
  if(_t[n] == 0) {
    Uint a = t(n-1);
    Uint b = t(n-2) + t(n-3);
    Uint p = _t.front();

    a *= a;
    a %= M;

    b %= M;
    b *= b;
    b %= M;

    Uint c = t(n-4) * t(n-5);
    c %= M;

    p *= p;
    p %= M;

    Uint res = a;
    res += b;
    res %= M;
    res += c;
    res %= M;
    res += p;
    res %= M;
    res += n;
    res %= M;

    _t[n] = res;
  }

  return _t[n];
}

Uint sum(size_t n) {
  if(_sum[n] == 0) {
    _sum[n] = sum(n-1) + t(n);
  }

  return _sum[n];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  size_t d, p;
  std::cin >> d >> p;

  int q;
  std::cin >> q;

  _t.resize(d);
  _t.front() = p;
  _sum.resize(d);
  for(int i=0; i<q; ++i) {
    int s, k;
    std::cin >> s >> k;
    std::cout << (sum(k) - sum(s-1)) << '\n';
  }
  
  /*
  std::cout << "----------------\n";
  for(const auto x : _t) {
    std::cout << x << '\n';
  }
  */

  return 0;
}

