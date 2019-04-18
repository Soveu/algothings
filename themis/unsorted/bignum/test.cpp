#include <iostream>

#include "stringnum2.cpp"

int main() {
  StringNum s1("246");
  StringNum s2("135");

  StringNum s3 = s1 + s2;

  std::cout << s3 << '\n';

  StringNum s4, s5;
  std::cin >> s4 >> s5;
  std::cout << "s4 = " << s4 << ", s5 = " << s5 << '\n';
  std::cout << "s4 + s5 = " << (s4 + s5) << '\n';
  std::cout << "s4 - s5 = " << (s4 - s5) << '\n';
  std::cout << "s4 * s5 = " << (s4 * s5) << '\n';
  std::cout << s4 << (s4 < s5 ? " < " : " >= ") << s5 << '\n';

  return 0;
}

