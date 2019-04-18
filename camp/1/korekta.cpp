#include<iostream>

using Int = long long int;

const char* map[32]{
  "??",
  "ac", 
  "ac", 
  "ac", 
  "df", 
  "df", 
  "df", 
  "gi", 
  "gi", 
  "gi", 
  "jl", 
  "jl", 
  "jl", 
  "mo", 
  "mo", 
  "mo", 
  "ps", 
  "ps", 
  "ps", 
  "ps", 
  "tv", 
  "tv", 
  "tv", 
  "wz",
  "wz",
  "wz",
  "wz",
  "??",
  "??",
  "??",
  "??",
  "??"
};

bool czyKorekta(const std::string& a, const std::string& b) {
  for(size_t j=0; j<a.size(); ++j) {
    char letterFrom = a[j] & 0x1f;
    char letterTo   = b[j] | 0x20;

    const char* letterRange = map[letterFrom];
    if(letterTo < letterRange[0] || letterTo > letterRange[1]) {
      /*
      std::cout << "Nie można przejść z " << (int)letterFrom << " na " << (int)letterTo
        << '\n' << letterRange[0] << " - " << letterRange[1] << '\n';
        */
      return false;
    }
  }

  return true;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  Int q;
  std::cin >> q;

  for(Int i=0; i<q; ++i) {
    std::string from, to;
    std::cin >> from >> to;

    std::cout << (czyKorekta(from, to) ? "TAK\n" : "NIE\n");
  }

  return 0;
}

