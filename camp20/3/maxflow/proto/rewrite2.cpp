#include <iostream>
#include <vector>
#include <array>
#include <cmath>

struct Node {
  std::vector<int> neighbours;
  int depth;
  int parent;
  int value;
};

using Graph = std::vector<Node>;

struct DFSStruct {
  int vertex;
  int index;
};

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

Graph set_root(Graph g, int root) {
  std::vector<DFSStruct> stack;
  stack.push_back({root, g[root].neighbours.size()});

  while(!stack.empty()) {
    auto item = stack.back();
    if(item.index == 0) {
      stack.pop_back();
      g[item.vertex].depth = stack.size();
      continue;
    }
    item.index -= 1;

    if(g[item.vertex].neighbours[item.index] == g[item.vertex].parent) {
      if(item.index == 0) {
        stack.pop_back();
        g[item.vertex].depth = stack.size();
        continue;
      }
      item.index -= 1;
    }

    auto n = g[item.vertex].neighbours[item.index];
    g[n].parent = item.vertex;
    stack.back() = item;
    stack.push_back({n, g[n].neighbours.size()});
  }

  return g;
}

Graph sum_dfs(Graph g, int root) {
  std::vector<DFSStruct> stack;
  stack.push_back({root, g[root].neighbours.size()});

  while(!stack.empty()) {
    auto item = stack.back();
    if(item.index == 0) {
      g[g[item.vertex].parent].value += g[item.vertex].value;
      stack.pop_back();
      continue;
    }
    item.index -= 1;

    if(g[item.vertex].neighbours[item.index] == g[item.vertex].parent) {
      if(item.index == 0) {
        g[g[item.vertex].parent].value += g[item.vertex].value;
        stack.pop_back();
        continue;
      }
      item.index -= 1;
    }

    auto n = g[item.vertex].neighbours[item.index];
    g[n].parent = item.vertex;
    stack.back() = item;
    stack.push_back({n, g[n].neighbours.size()});
  }

  return g;
}

NDimentionalVector<int, 2> build_lca_array(const Graph& g) {
  auto maxdepth = 0;
  for(const auto& node : g) {
    maxdepth = std::max(node.depth, maxdepth);
  }

  size_t n = g.size();
  size_t logh = std::ceil(std::log(maxdepth) / std::log(2));

  NDimentionalVector<int, 2> parent;
  parent.resize({n, logh});

  for(size_t i=0; i<g.size(); ++i) {
    parent.get({i, 0}) = g[i].parent;
  }
  for(size_t i=1; i<parent.size(1); ++i) {
    for(size_t u=2; u<parent.size(0); ++u) {
      auto p = parent.get({u, i-1});
      parent.get({u, i}) = parent.get({p, i-1});
    }
  }

  return parent;
}

int log2(uint32_t x) {
  int counter = -1;
  while(x != 0) {
    x >>= 1;
    counter += 1;
  }
  return counter;
}

int lca(const NDimentionalVector<int, 2>& parent, const Graph& g, int a, int b) {
  if(a == b) {
    return a;
  }

  if(g[a].depth > g[b].depth) {
    std::swap(a, b);
  }

  uint32_t depthDiff = g[b].depth - g[a].depth;
  while(depthDiff != 0) {
    int raise_by = log2(depthDiff);
    b = parent.get({b, raise_by});
    depthDiff -= (1 << raise_by);
  }

  if(a == b) {
    return a;
  }

  for(size_t i=parent.size(1)-1; i>=0; --i) {
    auto pa = parent.get({a, i});
    auto pb = parent.get({b, i});
    if(pa != pb) {
      a = pa;
      b = pb;
    }
  }

  return parent.get({a, 0});
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n, k;
  std::cin >> n >> k;

  Graph g(n+1);
  for(int i=1; i<n; ++i) {
    int u, v;
    std::cin >> u >> v;
    g[u].neighbours.push_back(v);
    g[v].neighbours.push_back(u);
  }

  g[0].neighbours.push_back(1);
  g = set_root(std::move(g), 0);
  g[0].parent = -1;

  const auto lcaarray = build_lca_array(g);

  for(int i=0; i<k; ++i) {
    int u, v;
    std::cin >> u >> v;

    int a = lca(lcaarray, g, u, v);
    g[u].value += 1;
    g[v].value += 1;
    g[a].value -= 1;
    g[g[a].parent].value -= 1;
  }

  g = sum_dfs(std::move(g), 1);
  int max = 0;
  for(const auto& node : g) {
    max = std::max(max, node.value);
  }
  std::cout << max << '\n';

  return 0;
}

