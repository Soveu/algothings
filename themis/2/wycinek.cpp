#include<iostream>
#include<stdint.h>

int ciag[1000000];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int64_t n,s;
  int64_t back=0, front=0;
  int64_t sum=0, max=0;

  std::cin >> n >> s;

  for(int i=0; i<n; i++){
    std::cin >> ciag[i];
  }

  while(front < n) { 
    /* "skonsumuj" następną wartość */
    sum += ciag[front];

    /* skurcz gąsienice, jeśli sum > s */
    while(back < front && sum > s) {
      sum -= ciag[back];
      back++;
    }

    if(sum == s)
      max = std::max(max, front-back+1);

    front++;
  }

  std::cout << (max == 0 ? -1 : max) << '\n';

  return 0;
}

