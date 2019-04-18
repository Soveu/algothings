#include <vector>

class DisjoinSet : public std::vector<size_t> {
  DisjoinSet(size_t n) : std::vector<size_t>(n) {
    size_t i = 0;
    for(auto& x : *this) {
      x = i++;
    }
  }

  DisjoinSet(const DisjoinSet&) = default;
  DisjoinSet(DisjoinSet&&) = default;
  DisjoinSet& operator=(const DisjoinSet&) = default;
  DisjoinSet& operator=(DisjoinSet&&) = default;
  ~DisjoinSet() = default;

  size_t find(size_t n) {
    if((*this)[n] == n) {
      return n;
    }

    (*this)[n] = find(n);
    return (*this)[n];
  }

  void join(size_t a, size_t b) {

  }
};

