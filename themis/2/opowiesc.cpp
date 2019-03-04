#include<iostream>
#include<stdint.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::string s;
  bool czyBylo[256]{false};
  uint64_t ileFalszywych=0;

  std::cin >> n
    >> s;

  for(const auto c : s) {
    czyBylo[c] = true;
    ileFalszywych += czyBylo[c^0x20];
  }

/*
  for(char i='A'; i<='Z'; ++i)
    ileFalszywych += std::min(ileRazy[i], ileRazy[i+32]);
*/

  std::cout << ileFalszywych << '\n';

  return 0;
}

