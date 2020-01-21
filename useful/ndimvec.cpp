#include <iostream>
#include <vector>
#include <array>
#include <cmath>

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

