#include<iostream>

int main(){
  int x;
  std::string s;

  std::cin >> x >> s;

  int nawiasy=0;

  for(const auto& c : s){
    if(c == '('){
      nawiasy++;
    } else {
      nawiasy--;
      if(nawiasy < 0) break;
    }
  }

  std::cout << (nawiasy == 0 ? "TAK\n" : "NIE\n");

  return 0;
}
