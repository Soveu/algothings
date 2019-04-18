#include<iostream>

using Int = long long;

struct Complex {
  int real;
  int imag;
};

Complex pow2(const Complex& c) {
  Complex ret;
  ret.real = (c.real - c.imag) * (c.real + c.imag);
  ret.imag = 2 * c.real * c.imag;
  return ret;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;

  int ileKombinacji = 0;
  Complex c{0, 0};
  Complex r = pow2(c);
  while(r.imag < m) {
    c.imag++;

    while(r.real < n) {
      c.real++;

      if(c.real == c.imag)
        continue;

      r = pow2(c);
      ileKombinacji += 2;
//      std::cout << r.real << ' ' << r.imag << '\n';
    }

    c.real = 0;
  }

  std::cout << ileKombinacji << '\n';

  return 0;
}

