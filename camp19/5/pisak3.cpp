#include<iostream>
#include<array>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  for(int i=0; i<t; ++i) {
    int n;
    std::cin >> n;

    std::array<int, 10> weight;
    for(auto& w : weight) {
      std::cin >> w;
    }

    int maxLen = 0;
    int cheapestNumber = 0;
    for(int i=0; i<10; ++i) {
      int len = n / weight[i];

      if(len > maxLen) {
        cheapestNumber = i;
        maxLen = len;
      }
    }

    if(maxLen <= 0) {
      std::cout << "NIE\n";
      continue;
    }

    int reszta = n % weight[cheapestNumber];

    if(cheapestNumber == 0) {
      /* SCREAM FOR HELP */
      int secondCheapestNumber = 1;

      for(int i=2; i<10; ++i) {
        if(weight[i] < weight[secondCheapestNumber]) {
          secondCheapestNumber = i;
          weight[secondCheapestNumber] = weight[i];
        }
      }

      //DEBUG
      //std::cout << "weight[secondCheapestNumber] = " << weight[secondCheapestNumber] 
        //<< ", reszta = " << reszta << '\n';

      if(weight[secondCheapestNumber] > n) {
        std::cout << "NIE\n";
        continue;
      }
      
      int delta = weight[secondCheapestNumber] / weight[0];
      if(weight[secondCheapestNumber] % weight[0] != 0) {
        delta += 1;
      }

      maxLen -= delta;
      reszta += delta * weight[0]; 

      //DEBUG
      //std::cout << "maxLen = " << maxLen << '\n';

      std::cout << (char)('0' + secondCheapestNumber);
    }

    for(int i=9; i>cheapestNumber; --i) {
      weight[i] -= weight[cheapestNumber];
    }

    for(int i=9; i>cheapestNumber; --i) {
      while(reszta >= weight[i] && maxLen > 0) {
        reszta -= weight[i];
        std::cout << (char)('0' + i);
        maxLen--;
      }
    }

    for(int i=0; i<maxLen; ++i) {
      std::cout << (char)('0' + cheapestNumber);
    }

    std::cout << '\n';
  }

  return 0;
}

