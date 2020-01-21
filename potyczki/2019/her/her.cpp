#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int t;
  std::cin >> t;

  for(int i=0; i<t; ++i) {
    int n;
    std::cin >> n;

    int currentTotalHeat = 0;
    int currentMinTemp = std::numeric_limits<int>::max();
    int currentMaxTemp = std::numeric_limits<int>::min();
    int expectedTotalHeat = 0;
    int expectedMinTemp = std::numeric_limits<int>::max();
    int expectedMaxTemp = std::numeric_limits<int>::min();

    for(int j=0; j<n; ++j) {
      int volume, currentTemp, expectedTemp;
      std::cin >> volume >> currentTemp >> expectedTemp;

      currentTotalHeat += volume * currentTemp;
      currentMinTemp = std::min(currentMinTemp, currentTemp);
      currentMaxTemp = std::max(currentMaxTemp, currentTemp);
      expectedTotalHeat += volume * expectedTemp;
      expectedMinTemp = std::min(expectedMinTemp, expectedTemp);
      expectedMaxTemp = std::max(expectedMaxTemp, expectedTemp);
    }

    const char* result = "NIE\n";
    if(currentTotalHeat == expectedTotalHeat &&
      ((expectedMinTemp > currentMinTemp && expectedMaxTemp < currentMaxTemp) ||
      (expectedMinTemp == currentMinTemp && expectedMaxTemp == currentMaxTemp)))
    {
      result = "TAK\n";
    }

    std::cout << result;
  }

  return 0;
}

