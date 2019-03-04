#include<iostream>
#include<stdint.h>

/* dżdżownica 
 *  1  2 1 0 3 5
 * (1) 2 1 0 3 5
 * (1 2) 1 0 3 5
 * (1 2 1) 0 3 5
 * (1 2 1 0) 3 5
 * (1 2 1 0 3) 5
 * 1 (2 1 0 3) 5
 */

int64_t ciag[1000000];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int64_t n, k, max, sum=0;

  std::cin >> n >> k;

  for(int64_t i=0; i<n; ++i){
    std::cin >> ciag[i];
  }

  for(int64_t i=0; i<k; ++i){
    sum += ciag[i];
  }
  max = sum;

  for(int64_t i=k; i<n; ++i){
    sum += (ciag[i] - ciag[i-k]);
    if(sum > max) max = sum;
  }

  std::cout << max << '\n';

  return 0;
}

