#include<iostream>
#include<string>

struct Cyfra {
  int index;
  int koszt;
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  for(int i=0; i<t; ++i) {
    int n;
    std::cin >> n;

    Cyfra cyfry[10];
    for(int i=0; i<10; ++i) {
      std::cin >> cyfry[i].koszt;
      cyfry[i].index = i;
    }

    int maxLen = 0;
    int cheapNum = 0;
    for(int i=0; i<10; ++i) {
      int newLen = n / cyfry[i].koszt;
      if(newLen > maxLen) {
        cheapNum = i;
        maxLen = newLen;
      }
    }

    if(maxLen <= 0) {
      std::cout << "NIE\n";
      continue;
    }

    int reszta = n % cyfry[cheapNum].koszt;
    for(int i=cheapNum+1; i<10; ++i) {
      cyfry[i].koszt -= cyfry[cheapNum].koszt;
    }

    if(cheapNum == 0) {
      /* SCREAM FOR HELP */
      int replacement = 0;
      int delta = 0;

      for(int i=9; i>0; --i) {
        if(delta > cyfry[i].koszt) {
          replacement = i;
          delta = cyfry[i].koszt;
        }
      }

      if(replacement == 0) {
        std::cout << "NIE\n";
        return 0;
      } else {
        std::cout << (char)('0' + replacement);
        maxLen--;
        reszta -= delta;
      }
    }

    for(int i=9; i>cheapNum; --i) {
      while(reszta >= cyfry[i].koszt && maxLen > 0) {
        reszta -= cyfry[i].koszt;
        std::cout << (char)('0' + i);
        maxLen--;
      }
    }

    for(int i=0; i<maxLen; ++i) {
      std::cout << (char)('0' + cheapNum);
    }

    std::cout << '\n';
  }
}

