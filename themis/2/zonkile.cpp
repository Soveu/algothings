#include<iostream>
#include<vector>
#include<string>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  std::string s;
  std::vector<int> sumaKwiatow;
  int n, q;
  int a, b;
  int sum=0;

  std::cin >> n
    >> s
    >> q;

  sumaKwiatow.resize(s.size());
  sumaKwiatow[0] = 0;

  for(int i=0; i<s.size(); ++i)
    sumaKwiatow[i+1] = (s[i] == '.' ? sum : ++sum);

  for(int i=0; i<q; ++i) {
    std::cin >> a >> b;
    std::cout << (sumaKwiatow[b] - sumaKwiatow[a-1]) << ' ';
  }

  std::cout << '\n';

  return 0;
}

