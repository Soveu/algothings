#include<iostream>
#include<utility>
#include<algorithm>
#include<array>

struct Cyfra {
  int index;
  int tusz;
};

int n;

bool comp(const Cyfra& a, const Cyfra& b) {
  if(a.tusz == b.tusz) {
    return a.index > b.index;
  }

  return a.tusz < b.tusz;
}

bool comp2(const Cyfra& a, const Cyfra& b) {
  return a.index * (b.tusz - n) > b.index * (a.tusz - n);
}

int main() {
  //std::ios_base::sync_with_stdio(false);
  //std::cin.tie(0);

  int t;
  std::cin >> t;

  for(int i=0; i<t; ++i) {
    std::cin >> n;

    std::array<Cyfra, 10> cyfry;
    for(int i=0; i<10; ++i) {
      cyfry[i].index = i;
      std::cin >> cyfry[i].tusz;
    }

    std::sort(cyfry.begin(), cyfry.end(), comp2);

    // DEBUG
    for(const auto& cyfra : cyfry) {
      printf("(%d, %d)\n", cyfra.tusz, cyfra.index);
    }

    if(n < cyfry.front().tusz) {
      std::cout << "NIE\n";
      continue;
    }

    std::string wynik;
    while(n >= cyfry.front().tusz) {
      n -= cyfry.front().tusz;
      wynik += (char)('0' + cyfry.front().index);
    }

    int changed = 0;
    int currentNum = 0;
    for(int i=1; i<10; ++i) {
      int delta = cyfry[i].tusz - cyfry[currentNum].tusz;
      if(delta < 0) {
        continue;
      }
      if(delta <= n && wynik[changed] - '0' < cyfry[i].index) {
        wynik[changed] = (char)('0' + cyfry[i].index);
        n -= delta;
        currentNum = i;
      }
    }

//    std::cout << wynik << "\tRESZTA = " << n << '\n';
    std::cout << wynik << '\n';
  }

  return 0;
}

