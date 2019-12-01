#include <stdint.h>

#include <iostream>
#include <vector>

int64_t answer(const std::vector<int> coins, int n) {
  std::vector<int64_t> dp(n+1);
  dp[0] = 1;

  for(const int& coin : coins) {
    for(int i=coin; i<dp.size(); ++i) {
      dp[i] += dp[i-coin];
    }
  }

  return dp.back();
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;

  std::vector<int> coins(m);
  for(auto& coin : coins) {
    std::cin >> coin;
  }

  std::cout << answer(coins, n) << '\n';
  return 0;
}

