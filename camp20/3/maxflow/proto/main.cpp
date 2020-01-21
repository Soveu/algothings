#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cmath>

struct Node {
  std::vector<int> neighbours;
  int value;
  int parent;
  int depth;
};

using Graph = std::vector<Node>;

struct DFSStruct {
  int vertex;
  int i;
};

/* TODO: this is wrong */
int lca(const Graph& g, int a, int b) {
  if(a == 1 || b == 1) {
    return 1;
  }
  if(a == b) {
    return a;
  }

  if(g[a].depth > g[b].depth) {
    return lca(g, b, a);
  }

  while(g[b].depth > g[a].depth) {
    b = g[b].parent;
  }
  while(a != b) {
    a = g[a].parent;
    b = g[b].parent;
  }

  return a;
}

Graph set_root(Graph g, int root) {
  std::vector<DFSStruct> stack;

  stack.push_back({root, 0});
  while(!stack.empty()) {
    auto u = &stack.back();
    if(u->i == g[u->vertex].neighbours.size()) {
      stack.pop_back();
      continue;
    }

    g[u->vertex].depth = stack.size()-1;

    if(g[u->vertex].neighbours[u->i] == g[u->vertex].parent) {
      u->i += 1;
      if(u->i == g[u->vertex].neighbours.size()) {
        stack.pop_back();
        continue;
      }
    }

    int n = g[u->vertex].neighbours[u->i];
    std::cout << "n=" << n << std::endl;
    g[n].parent = u->vertex;
    u->i += 1;
    stack.push_back({n, 0});
  }

  return g;
}

Graph dfs(Graph g, int root) {
  std::vector<int> stack;
  std::vector<bool> working(g.size());

  stack.push_back(root);
  while(!stack.empty()) {
    int u = stack.back();
    if(working[u]) {
      g[g[u].parent].value += g[u].value;
      stack.pop_back();
      continue;
    } else {
      working[u] = true;
    }

    for(const auto n : g[u].neighbours) {
      if(n != g[u].parent) {
        stack.push_back(n);
      }
    }
  }

  return g;
}

/* p[i][0] = g[i].parent */
/* p[u][i] = p[ p[u][i-1] ][i-1] */
using LCAArray = std::vector<std::vector<int>>;
LCAArray build_lca_array(const Graph& g, int root) {
  int n = g.size();
  int logn = std::ceil(std::log(n) / std::log(2));
  std::cout << "n=" << n << " logn=" << logn << std::endl;

  LCAArray p(n);
  for(auto& v : p) {
    v.resize(logn);
  }

  for(int i=0; i<g.size(); ++i) {
    p[i][0] = g[i].parent;
  }
  for(int i=1; i<logn; ++i) {
    for(int u=2; u<n; ++u) {
      int pp = p[u][i-1];
      std::cout << "u=" << u << " i=" << i << std::endl;
      p[u][i] = p[pp][i-1];
    }
  }

  std::cout << "LCA ARRAY\n";
  for(int i=0; i<n; ++i) {
    std::cout << i << ": ";
    for(int j=0; j<logn; ++j) {
      std::cout << p[i][j] << ' ';
    }
    std::cout << std::endl;
  }

  return p;
}

int log2(uint32_t x) {
  int counter = -1;
  while(x != 0) {
    x >>= 1;
    counter += 1;
  }
  return counter;
}

int lca_better(const LCAArray& p, const Graph& g, int a, int b) {
  if(a == b) {
    return a;
  }

  int adepth = g[a].depth;
  int bdepth = g[b].depth;
  if(adepth > bdepth) {
    return lca_better(p, g, b, a);
  }

  uint32_t depthDiff = bdepth - adepth;
  /*
  int counter = 0;
  while(depthDiff != 0) {
    if(g[b].depth != g[a].depth + depthDiff) {
      std::cout << "ERROR g[b].depth=" << g[b].depth << " g[a].depth=" << g[a].depth << " depthDiff=" << depthDiff << std::endl;
      exit(1);
    }
    int bit = depthDiff & 1;
    if(bit == 1) {
      b = p[b][counter];
      counter = 0;
    } else {
      counter += 1;
    }

    depthDiff >>= 1;
  }
  */
  while(depthDiff != 0) {
    int raise_by = log2(depthDiff);
    b = p[b][raise_by];
    depthDiff -= (1 << raise_by);
    if(g[b].depth != g[a].depth + depthDiff) {
      std::cout << "ERROR g[b].depth=" << g[b].depth << " g[a].depth=" << g[a].depth << " depthDiff=" << depthDiff << std::endl;
      exit(1);
    }
  }

  if(g[b].depth != g[a].depth) {
    std::cout << "ERROR g[b].depth=" << g[b].depth << " g[a].depth=" << g[a].depth << std::endl;
    exit(1);
  }
  if(a == b) {
    return a;
  }

  /* TODO */
  /*
  while(p[a][0] != p[b][0]) {
    int i=1;
    while(i<p[a].size() && i<p[b].size() && p[a][i] != p[b][i]) {
      ++i;
    }
    i -= 1;
    a = p[a][i];
    b = p[b][i];
    // does it work?
  }
  */
  for(int i=p[a].size()-1; i>=0; --i) {
    if(p[a][i] != p[b][i]) {
      a = p[a][i];
      b = p[b][i];
    }
  }

  return p[a][0];
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
  for(int i=0; i<g.size(); ++i) {
    std::cout << i << ": depth=" << g[i].depth << " parent=" << g[i].parent << std::endl;
  }

  const auto lcaarray = build_lca_array(g, 1);
  for(int i=0; i<k; ++i) {
    int u, v;
    std::cin >> u >> v;

    int a = lca_better(lcaarray, g, u, v);
    std::cout << "u=" << u << " v=" << v << ' ';
    std::cout << "a=" << a << " parent=" << g[a].parent << std::endl;
    g[u].value += 1;
    g[v].value += 1;
    g[a].value -= 1;
    g[g[a].parent].value -= 1;
  }

  g = dfs(std::move(g), 1);
  int max = 0;
  for(const auto& node : g) {
    max = std::max(max, node.value);
  }
  std::cout << max << '\n';

  return 0;
}

