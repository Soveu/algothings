#include<iostream>

template <typename T, size_t N>
struct Stos {
  T arr[N];
  size_t _top = 0;

  T& push(const T& x) {
    return arr[++_top] = x;
  }

  T pop() {
    return arr[_top--];
  }

  T& top() {
    return arr[_top];
  }

  size_t max() const {
    return N;
  }

  size_t size() const {
    return _top;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  int a[500000];
  Stos<int, 500000> s;
  for(int i=0; i<n; ++i) {
    std::cin >> a[i];
  }

  return 0;
}

