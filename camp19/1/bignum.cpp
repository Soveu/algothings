#include <stdint.h>
#include <vector>
#include <utility>

#include <iostream>

struct Bigint {
  using bigger_t  = uint32_t;
  using smaller_t = uint16_t;

  std::vector<smaller_t> num;

  bool operator>(const Bigint& a) const {
    if(this->num.size() > a.num.size()) {
      return true;
    }
    if(this->num.size() < a.num.size()) {
      return false;
    }

    for(size_t i=0; i<this->num.size(); ++i) {
      if(this->num[i] <= a.num[i]) {
        return false;
      }
    }

    return true;
  }

  bool operator==(const Bigint& a) {
    if(this->num.size() != a.num.size()) {
      return false;
    }

    for(size_t i=0; i<this->num.size(); ++i) {
      if(this->num[i] != a.num[i]) {
        return false;
      }
    }

    return true;
  }

  Bigint& shift_left_self(const size_t n) {
    const size_t smallerBitSize = sizeof(smaller_t) * 8;
    const size_t blockShift = n/smallerBitSize;
    const size_t bitShift = n%smallerBitSize;

    if(blockShift > 0) {
      this->shift_left_block_self(blockShift);
    }

    if(num.back() > (2 << (smallerBitSize - bitShift))) {
      this->num.push_back(0);
    }

    smaller_t tmp[2];
    bigger_t& _tmp = *((bigger_t*)tmp);

    auto it = this->num.rbegin();
    const size_t shift = n % smallerBitSize;
    ++it;
    while(it != this->num.rend()) {
      _tmp = *it;
      _tmp <<= shift;
      *(it-1) += tmp[1];
      *it = tmp[0];
      ++it;
    }

    return *this;
  }

  Bigint& shift_left_block_self(const size_t n) {
    size_t oldSize = this->num.size();
    this->num.resize(oldSize + n);

    for(ssize_t i=oldSize-1; i>=0; --i) {
      this->num[i+n] = this->num[i];
      this->num[i] = 0;
    }

    return *this;
  }

  smaller_t divide_self(const smaller_t x) {
    auto it = this->num.rbegin();
    smaller_t reszta = *it % x;
    smaller_t iloraz = *it / x;
    *it = iloraz;
    ++it;

    while(it != this->num.rend()) {
      bigger_t suma = *it + (reszta << (sizeof(smaller_t) * 8));
      reszta = suma % x;
      iloraz = suma / x;
      *it = iloraz;
      ++it;
    }

    return reszta;
  }

  void subtract_blocks(size_t from, size_t to, const Bigint& x) {
    while(from < to) {
      bigger_t x = this->num[from];
      if(x /*TODO*/) {

      }
    }
  }

  Bigint divide_self(const Bigint& x) {
    if(x > *this) {
      Bigint ret;
      ret.num = std::move(this->num);
      this->num.push_back(0);
      return ret;
    }

    size_t deltaBlocks = this->num.size() - x.num.size();
    bigger_t reszta = 0;

    for(ssize_t i=this->num.size()-1; i>=0; --i) {
      for(size_t j=0; j<deltaBlocks; ++j) {
        this->num[i-j] -= x.num[x.size()-j-1];
      }
    }

    return *this;
  }
};

bool test_small() {
  Bigint big;
  int x = 3;

  int a = 2 + (4<<16);
  big.num.push_back(2);
  big.num.push_back(4);
  
  auto r = big.divide_self(x);
  auto p = *((int*)big.num.data());

  std::cout << "p = " << p << ", a/x = " << a/x << '\n'
    << "r = " << r << ", a%x = " << a%x << '\n';

  return (p == a/x && r == a%x);
}

void test_shift() {
  Bigint big;
  int a = 2 + (4<<16);
  big.num.push_back(2);
  big.num.push_back(4);

  a <<= 2;
  big.shift_left_self(2);
  auto p = *((int*)big.num.data());

  std::cout << a << '\n' << p << '\n';
}

int main() {
  test_shift();
  return 0;
}

