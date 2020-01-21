#include <iostream>

int nearest_four_power(int x) {
  int ans = 1;
  while(ans <= x) {
    ans <<= 2;
  }
  return ans >> 2;
}

int main() {
  int n;
  std::cin >> n;

  const int base = 4;
  int node = 1;
  int nextnode;
  
  while(node < n) {
    for(int dist=n-node; dist != 0; dist >>= 2) {
      nextnode = node+dist;
    std::cout << "------------------------\n";
    }
    //nextnode = nearest_four_power(nextnode);
    std::cout << node << ' ' << nextnode << '\n';
    node = nextnode;
  }

  return 0;
}

