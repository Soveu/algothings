#include<iostream>

struct Wieza{
  int x,y;
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  size_t ileTestów;
  Wieza wieze[0xFFFF];

  std::cin >> ileTestow;

  for(int i=0; i<ileTestow; i++){
    size_t maxPole=0;

    std::cin >> szerokosc >> wysokosc >> x;

    for(int j=0; j<x; j++){
      std::cin >> wieze[j].x >> wieze[j].y;
    }

    std::cout << maxPole << '\n';
  }

  return 0;
}

