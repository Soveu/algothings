#include<iostream>

#define ORZEL   'A'
#define RESZKA  'B'

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  std::string s;
  ssize_t counter=0; 
  size_t max=0, back=0, front=0;

  std::cin >> s;

  while(front < s.size()) {
    counter += (s[front] == ORZEL ? 1 : -2);

    while(back < front && counter > 0) {
      counter += (s[back] == ORZEL ? -1 : 2);
      ++back;
    }

    if(counter == 0)
      max = std::max(max, front-back+1);

    ++front;
  }

  std::cout << max << '\n';

  return 0;
}

