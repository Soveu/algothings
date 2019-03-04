#include<stdint.h>
#include<iostream>

int main() {
  int const n = 10;
  int back=0, front=0, ans=-1;
  uint64_t sum=0, s=10, tab[n]{0,1,2,3,4,5,6,7,8,9};

/*
  while(back < n) {
    sum += tab[front];
    if(sum <= x) {
      if(sum == x) ans = std::max(ans, front-back+1);
      front++;
    } else {
      sum -= tab[back];
      back++;
    }
  }
*/

  while(front < n) { /* było back, powinno być front? */
    sum += tab[front]; /* "skonsumuj" następną wartość */

    if(0);

    /* skurcz gąsienice, jeśli sum > s */
    while(back <= front && sum > s) {
      sum -= tab[back];
      back++;
    }

    /* Jeżeli aktualna suma == szukanej sumie, to jeżeli aktualna suma jest 
     * większa od największej znalezionej, to nadpisz ją */
    if(sum == s)
      ans = std::max(ans, front-back+1);

    front++;
  }

  std::cout << sum << ' ' 
    << back << '/'
    << front << ' '
    << ans
    << '\n';


}

