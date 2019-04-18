#include<iostream>
#include<vector>
#include<algorithm>

struct Solanka {
  int ilosc, stezenie;
};

bool comparator(const Solanka& a, const Solanka& b) {
  return a.stezenie < b.stezenie;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int n, k;
  std::cin >> n >> k;

  long long salt = 0;
  long long totalMass = 0;
  std::vector<Solanka> vs(n);
  for(auto& s : vs) {
    int stezenie, ilosc;
    std::cin >> stezenie >> ilosc;

    s.stezenie = stezenie;
    s.ilosc = ilosc;

    salt += stezenie * ilosc;
    totalMass += ilosc;
  }

  if(std::abs((double)salt/totalMass - k) < 0.001) {
    std::cout << totalMass << '\n';
    return 0;
  }

  std::sort(vs.begin(), vs.end(), comparator);

  /* sprawdzić czy jest to wgl możliwe */
  if(vs.front().stezenie > k || vs.back().stezenie < k) {
    std::cout << "000.000\n";
    return 0;
  }

  salt = 0;
  totalMass = 0;
  for(const auto& s : vs) {
    salt += s.ilosc * s.stezenie;
    totalMass += s.ilosc;

    if(salt == totalMass * k) {
      std::cout << totalMass << '\n';
      return 0;
    }
    if(salt > totalMass * k) {
      double res = (double)(salt - k * totalMass) / (s.stezenie - k);
      return 0;
    }
  }

  /* k is bigger */
  for(const auto& s : vs) {
    salt -= s.ilosc * s.stezenie;
    totalMass -= s.ilosc;

    if(salt == totalMass * k) {
      std::cout << totalMass << '\n';
      return 0;
    }
    if(salt > totalMass * k) {
      double res = (double)(salt - k * totalMass) / (k - s.stezenie);
      std::cout << totalMass+res << '\n';
      return 0;
    }
  }

  /* ????????????????????? */
  std::cout << "???????????????\n";

  return 0;
}

