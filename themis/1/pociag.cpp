#include<iostream>

void mv(size_t a, size_t b, size_t osobowe[6]){
  /* a + b -> a+b */
  if(osobowe[a] < osobowe[b]){
    osobowe[a+b] += osobowe[a];
    osobowe[b] -= osobowe[a];
    osobowe[a] = 0;
  } else {
    osobowe[a+b] += osobowe[b];
    osobowe[a] -= osobowe[b];
    osobowe[b] = 0;
  }
}

int main() {
  size_t przedzialy;
  size_t osobowe[6]{0};
  size_t tmp;
  size_t wynik=0;

  std::cin >> przedzialy;

  for(size_t i=0; i<przedzialy; ++i){
    std::cin >> tmp;
    osobowe[tmp]++;
  }

  /* 1 + 4 -> 5 */
  if(osobowe[1] < osobowe[4]){
    osobowe[5] += osobowe[1];
    osobowe[4] -= osobowe[1];
    osobowe[1] = 0;
  } else {
    osobowe[5] += osobowe[4];
    osobowe[1] -= osobowe[4];
    osobowe[4] = 0;
  }

  /* 2 + 3 -> 5 */
  if(osobowe[2] < osobowe[3]){
    osobowe[5] += osobowe[2];
    osobowe[3] -= osobowe[2];
    osobowe[2] = 0;
  } else {
    osobowe[5] += osobowe[3];
    osobowe[2] -= osobowe[3];
    osobowe[3] = 0;
  }

  /* 1 + 3 -> 4 */
  if(osobowe[1] < osobowe[3]){
    osobowe[4] += osobowe[1];
    osobowe[3] -= osobowe[1];
    osobowe[1] = 0;
  } else {
    osobowe[4] += osobowe[3];
    osobowe[1] -= osobowe[3];
    osobowe[3] = 0;
  }

  /* 1 + 4 -> 5 */
  if(osobowe[1] < osobowe[4]){
    osobowe[5] += osobowe[1];
    osobowe[4] -= osobowe[1];
    osobowe[1] = 0;
  } else {
    osobowe[5] += osobowe[4];
    osobowe[1] -= osobowe[4];
    osobowe[4] = 0;
  }

  /* 1 + 2 -> 3 */
  if(osobowe[1] < osobowe[2]){
    osobowe[3] += osobowe[1];
    osobowe[2] -= osobowe[1];
    osobowe[1] = 0;
  } else {
    osobowe[3] += osobowe[2];
    osobowe[1] -= osobowe[2];
    osobowe[2] = 0;
  }

  /* 2 + 3 -> 5 */
  if(osobowe[2] < osobowe[3]){
    osobowe[5] += osobowe[2];
    osobowe[3] -= osobowe[2];
    osobowe[2] = 0;
  } else {
    osobowe[5] += osobowe[3];
    osobowe[2] -= osobowe[3];
    osobowe[3] = 0;
  }

  for(size_t i=1; i<6; ++i){
    wynik += osobowe[i];
  }

  std::cout << wynik << '\n';

  return 0;
}


  
