#include <iostream>
#include <vector>
#include <unordered_set>

template <typename T, size_t N>
struct NDimentionalVector {
  std::vector<T> vec;
  std::array<size_t, N> dimentions;

  size_t allocated_size() const {
    return this->vec.size();
  }
  size_t size(size_t n) const {
    return this->dimentions[n];
  }

  const T& get(const std::array<size_t, N>& coords) const {
    size_t index = coords[0];
    for(size_t i=1; i<N; ++i) {
      index += coords[i] * this->dimentions[i-1];
    }
    return this->vec[index];
  }
  T& get(const std::array<size_t, N>& coords) {
    size_t index = coords[0];
    for(size_t i=1; i<N; ++i) {
      index += coords[i] * this->dimentions[i-1];
    }
    return this->vec[index];
  }

  const T& operator[](const std::array<size_t, N>& coords) const {
    return this->get(coords);
  }
  T& operator[](const std::array<size_t, N>& coords) {
    return this->get(coords);
  }

  void resize(const std::array<size_t, N>& dims) {
    this->dimentions = dims;
    size_t sz = dims[0];
    for(size_t i=1; i<N; ++i) {
      sz *= dims[i];
    }
    this->vec.resize(sz);
  }
};

std::vector<int> lcs(const std::vector<int>& a, const std::vector<int>& b) {
  std::vector<int> res;
  NDimentionalVector<int, 2> dp;
  dp.resize({a.size()+1, b.size()+1});

  for(int j=1; j<=b.size(); ++j) {
    for(int i=1; i<=a.size(); ++i) {
      if(a[i-1] == b[j-1]) {
        dp.get({i, j}) = dp.get({i-1, j-1}) + 1;
      } else {
        dp.get({i, j}) = std::max(dp.get({i, j-1}), dp.get({i-1, j}));
      }
    }
  }

  int i=a.size(), j=b.size();
  while(i != 0 && j != 0) {
    if(a[i-1] == b[j-1]) {
      i -= 1;
      j -= 1;
      res.push_back(a[i]);
      continue;
    }
    if(dp.get({i-1, j}) > dp.get({i, j-1})) {
      i -= 1;
      continue;
    }
    j -= 1;
  }

  return res;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(n);
  std::vector<int> b(m);

  for(auto& x : a) {
    std::cin >> x;
  }
  for(auto& x : b) {
    std::cin >> x;
  }

  auto substr = lcs(a, b);
  std::unordered_set<int> notInPair;

  int counter = 0;
  for(const int x : substr) {
    auto it = notInPair.find(x);
    if(it == notInPair.end()) {
      notInPair.insert(x);
    } else {
      counter += 2;
      notInPair.erase(it);
    }
  }

  std::cout << counter << '\n';
}

