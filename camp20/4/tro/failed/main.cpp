#include <iostream>
#include <stdint.h>

#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cmath>

#define DEBUG_PRINT(x) (x)

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n, subtask;
  std::cin >> n;

  if(n == 3) {
    std::cout << "3\n1 2\n2 3\n3 1\n";
    return 0;
  }

  std::vector<std::pair<int, int>> ans;
  ans.reserve(5*n);
  
  int in1=1, out1=n/2;
  int in2=out1+1, out2=n;

  for(int i=in1+1; i<out1; ++i) {
    ans.push_back({in1, i});
    ans.push_back({i, out1});
  }
  ans.push_back({in1,out1});

  for(int i=in2+1; i<out2; ++i) {
    ans.push_back({in2, i});
    ans.push_back({i, out2});
  }
  ans.push_back({in2, out2});

  ans.push_back({out1, in2});
  ans.push_back({out1, out2});

  ans.push_back({out2, in1});
  ans.push_back({in2, in1});

  std::cout << ans.size() << '\n';
  for(const auto& kv : ans) {
    std::cout << kv.first << ' ' << kv.second << '\n';
  }

  return 0;
}

