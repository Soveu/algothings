#include<iostream>
#include<string>
#include<algorithm>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;

  for(int i=0; i<n; ++i) {
    std::string a, b;
    std::cin >> a >> b;

    int deltaBlocks = a.size() - b.size();
    if(deltaBlocks < 0) {
      std::cout << "0\n";
      continue;
    }

    for(auto& c : a) {
      c -= '0';
    }
    for(auto& c : b) {
      c -= '0';
    }
  }

  return 0;
}

