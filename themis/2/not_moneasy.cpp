#include<iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  std::string s;
  char currentChar;

  /* 'A' -> counter[0]; 'B' -> counter[1] 
   * 'A' == orzeł;      'B' == reszka */
  size_t counter[2]{0, 0}; 
  size_t len=0, maxlen=0;

  std::cin >> s;
  currentChar = s[0];
  counter[currentChar-'A']++;
  auto ptr = s.begin();

  for(;;) {
    while(*ptr++ == currentChar)
      counter[currentChar-'A']++;

/*
    if (counter[0] >= 2 * counter[1]) {
      len = counter[0] + counter[1];
      break;
    }
*/

    len = (counter[0] > 2 * counter[1] ? 
        counter[1] * 3 :
        (counter[0] * 3) / 2);
    maxlen = std::max(maxlen, len);

    /* Flip between 'A' and 'B' */
    currentChar = 'A' + ('B' - currentChar);
    counter[currentChar-'A'] = 0;
  }

  std::cout << len << '\n';

  return 0;
}

