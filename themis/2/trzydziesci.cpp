#include<iostream>
#include<string>
#include<algorithm>

/* dzieli się przez 30 == dzieli się przez 3 && dzieli się przez 10
 * dzieli się przez 10 == (ostatnia cyfra == 0)
 * dzieli się przez  3 == (suma cyfr % 3 == 0)
 */

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  std::string s;
  ssize_t suma=0;
  bool byloZero=false;
  
  std::cin >> s;

  for(const auto c : s){
    char t = c - '0';
    if(t == 0)
      byloZero = true;

    suma += t;
  }

  if(suma % 3 == 0 and byloZero) {
    /* Jest podzielna przez 30 po zamianie znaków */
    std::sort(s.rbegin(), s.rend());
    std::cout << s;
  } else {
    std::cout << -1;
  }

  std::cout << '\n';

  return 0;
}

