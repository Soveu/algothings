#include "stringnum.hpp"

StringNum& StringNum::strip() {
  size_t zeroesCount = 0;
  auto it = this->rbegin();

  while(it != this->rend() && *it == '0') {
    ++it;
    ++zeroesCount;
  }

  this->resize(this->size() - zeroesCount);

  return *this;
}

StringNum::StringNum(const char* s) : std::string(s) {
  std::reverse(this->begin(), this->end());
  this->strip();
}

StringNum::StringNum(const std::string& s) : std::string(s) {
  std::reverse(this->begin(), this->end());
  this->strip();
}

StringNum& StringNum::operator+=(const StringNum& sn) {
  if(this->size() < sn.size()) {
    this->resize(sn.size(), '0');
  }

  int carry = 0;
  for(size_t i=0; i<sn.size(); ++i) {
    int a = (*this)[i] - '0';
    int b = sn[i] - '0';

    a += (b + carry);

    carry = a / 10;
    (*this)[i] = (a % 10) + '0';
  }

  if(carry == 0) {
    return *this;
  }

  if(this->size() == sn.size()) {
    this->push_back(carry + '0');
  } else {
    int a = (*this)[sn.size()] - '0';
    a += carry;
    carry = a / 10;
    (*this)[sn.size()] = (a % 10) + '0';

    auto it = this->begin() + sn.size();
    while(carry != 0) {
      ++it;
      if(it == this->end()) {
        this->push_back(carry + '0');
        break;
      }
      a = *it - '0';
      a += carry;
      carry = a / 10;
      *it = (a % 10) + '0';
    }
  }
  
  return *this;
}

StringNum& StringNum::operator-=(const StringNum& sn) {
  if(*this < sn) {
    return *this; // peacefully return
  }

  StringNum tmp = sn;
  if(tmp.size() < this->size()) {
    tmp.append(this->size() - tmp.size(), '0');
  }

  for(auto& c : tmp) {
    c = '9' + '0' - c;
  }
  tmp += StringNum("1"); // TODO: operator+= for ints

  // TODO: copy the mechanic from operator += to save that pop_back()
  *this += tmp;
  this->pop_back();
  this->strip();

  return *this;
}

StringNum& StringNum::operator<<=(size_t n) {
  this->resize(this->size() + n);

  size_t i = this->size() - n - 1;
  (*this)[i+n] = (*this)[i];
  while(i--) {
    (*this)[i+n] = (*this)[i];
  }

  std::fill_n(this->begin(), n, '0');
  return *this;
}

/* TODO: test it */
StringNum& StringNum::operator>>=(size_t n) {
  auto from = this->end() - 1;
  auto to = from - n;

  while(to != this->begin() - 1) {
    *to = *from;
    --to; --from;
  }

  this->resize(this->size() - n);
  return *this;
}

StringNum& StringNum::operator*=(const StringNum& sn) {
  *this = *this * sn;
  return *this;
}

/* outside functions ----------------------------------------------- */
bool operator<(const StringNum& a, const StringNum& b) {
  if(a.size() != b.size()) {
    return a.size() < b.size();
  }

  for(size_t i=1; i<=a.size(); ++i) {
    if(a[a.size()-i] != b[a.size()-i]) {
      return a[a.size()-i] < b[a.size()-i];
    }
  }

  return false;
}

StringNum operator+(const StringNum& a, const StringNum& b) {
  StringNum res = a;
  res += b;
  return res;
}

StringNum operator-(const StringNum& a, const StringNum& b) {
  StringNum res = a;
  res -= b;
  return res;
}

StringNum operator<<(const StringNum& a, const size_t n) {
  StringNum res = a;
  res <<= n;
  return res;
}

StringNum operator>>(const StringNum& a, const size_t n) {
  StringNum res = a;
  res >>= n;
  return res;
}

StringNum operator*(const StringNum& a, const StringNum& b) {
  StringNum tmp = a;
  StringNum res;

  for(auto c : b) {
    for(int i=0; i < c-'0'; ++i) {
      res += tmp;
    }

    tmp <<= 1;
  }

  return res;
}

/* Input/Output ---------------------------------------------------- */
std::istream& operator>>(std::istream& in, StringNum& sn) {
  in >> dynamic_cast<std::string&>(sn);
  std::reverse(sn.begin(), sn.end());
  sn.strip();
  return in;
}

std::ostream& operator<<(std::ostream& out, const StringNum& sn) {
  auto it = sn.rbegin();
  while(it != sn.rend()) {
    out << *it;
    ++it;
  }
  return out;
}

