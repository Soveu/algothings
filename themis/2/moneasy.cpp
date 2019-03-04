#include<iostream>

#define ORZEL   'A'
#define RESZKA  'B'

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  std::string s;
  ssize_t counter=0;
  size_t max=0;

  std::cin >> s;

  for(const auto x : s) {
    if(x == ORZEL)
      counter -= 1;
    else
      counter += 2;
  }

  auto right = s.end()-1;
  auto left  = s.begin();

  while(left != right) {
    if(counter == 0) {
      std::cout << std::distance(left, right) << '\n'
        << std::string(left, right) << '\n';
      break;
    } 
    else if(counter < 0) {
      if(ORZEL == *left) {
        counter += 1;
        ++left;
        continue;
      }
      if(ORZEL == *right) {
        counter += 1;
        --right;
        continue;
      }

      --right;
    } 
    else /* if(counter > 0) */{
      if(RESZKA == *left) {
        counter -= 2;
        ++left;
        continue;
      }
      if(RESZKA == *right) {
        counter -= 2;
        --right;
        continue;
      }

      ++left;
    }
  }

  return 0;
}

