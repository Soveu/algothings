#include <string>
#include <algorithm>
#include <iostream>

class StringNum : public std::string {
public:
  using std::string::string;

  using std::string::resize;
  using std::string::size;
  using std::string::length;
  using std::string::empty;

  using std::string::begin;
  using std::string::end;
  using std::string::rbegin;
  using std::string::rend;

  using std::string::operator=;
  using std::string::operator[];
  using std::string::at;

  using std::string::front;
  using std::string::back;
  using std::string::push_back;
  using std::string::pop_back;
  using std::string::append;
  using std::string::clear;
  using std::string::swap;

  StringNum(const char*);
  StringNum(const std::string&);

  StringNum() = default;
  StringNum(const StringNum&) = default;
  StringNum(StringNum&&) = default;
  StringNum& operator=(const StringNum&) = default;
  StringNum& operator=(StringNum&&) = default;
  ~StringNum() = default;

  StringNum& strip();
  StringNum& operator+=(const StringNum&);
  StringNum& operator-=(const StringNum&);
  StringNum& operator*=(const StringNum&);
  StringNum& operator<<=(size_t);
  StringNum& operator>>=(size_t);
};


StringNum operator+(const StringNum&, const StringNum&);
StringNum operator-(const StringNum&, const StringNum&);
StringNum operator*(const StringNum&, const StringNum&);
StringNum operator>>(const StringNum&, const size_t);
StringNum operator<<(const StringNum&, const size_t);

bool operator<(const StringNum& a, const StringNum& b);

std::istream& operator>>(std::istream& in, StringNum& sn);
std::ostream& operator<<(std::ostream& out, const StringNum& sn);

