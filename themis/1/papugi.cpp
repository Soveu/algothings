#include<iostream>

int main(void) {
  std::string x;

  std::cin >> x;

  for(int i=0; i<x.size(); ++i){
    std::cout << x << ' ';
  }

  std::cout << '\n';

  return 0;
}

