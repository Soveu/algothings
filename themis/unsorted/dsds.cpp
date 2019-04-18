#include <array>

struct DisjoinSetItem {
  size_t rep;
  int    count;
};

template<size_t N>
struct DisjoinSet : std::array<DisjoinSetItem, N> {
  DisjoinSet(size_t n) : std::array<DisjoinSetItem, N>() {
    size_t i = 0;
    for(auto& x : *this) {
      x.rep = ++i;
      x.count = 1;
    }
  }

  DisjoinSet(const DisjoinSet&) = default;
  DisjoinSet(DisjoinSet&&) = default;

  size_t find(size_t x) {
    if(x == (*this)[x].rep) {
      return x;
    }

    (*this)[x].rep = this->find(this->data()[x]);
    return (*this)[x].rep;
  }

  void join(size_t _a, size_t _b) {
    DisjoinSetItem& a = (*this)[this->find(_a)];
    DisjoinSetItem& b = (*this)[this->find(_b)];

    if(a.count > b.count) {
      b.repr = a.repr;
      a.count += b.count;
    } else {
      a.repr = b.repr;
      b.count += a.count;
    }
  }
};

