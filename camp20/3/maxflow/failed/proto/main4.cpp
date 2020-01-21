#include <iostream>
#include <stdint.h>

#include <unordered_map>
#include <cassert>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cmath>

#define DEBUG_PRINT(x) (x)

struct Node {
  std::vector<int> neighbours;
  int flow;
};

struct Pump {
  int end;
  int amount;
};

using Graph = std::vector<Node>;
using Pumps = std::map<std::pair<int, int>, int>;

Graph dfs(Graph g, const Pumps& p, const Pumps& pr) {
  enum Color {
    White,
    Grey,
    Black
  };
  std::vector<Color> colors(g.size());
  /* map (end, begin) of pump -> amount */
  std::map<std::pair<int, int>, int> goal;
  std::vector<int> stack;
  std::unordered_map<int, int> map;

  stack.push_back(0);
  while(!stack.empty()) {
    int u = stack.back();

    if(colors[u] == Color::White) {
      colors[u] = Color::Grey;
    } else if(colors[u] == Color::Grey) {
      colors[u] = Color::Black;
      stack.pop_back();
      continue;
    }

    auto it = goal.lower_bound({u,0});
    const auto begin = it;
    const auto end = goal.upper_bound({u, std::numeric_limits<int>::max()});

    int sum = 0;
    while(it != goal.end() && it->first.first == u) {
      int value = it->second;
      int vertex = it->first.second;
      map[vertex] = value;
      sum += value;
      ++it;
    }
    it = begin;

    for(auto i=stack.rbegin(); i != stack.rend(); ++i) {
      g[*i].flow += sum;
      auto vertex = map.find(*i);
      if(vertex != map.end()) {
        sum -= vertex->second;
      }
    }

    map.clear();
    goal.erase(begin, end);

    auto it1 = pr.lower_bound({u, 0});
    while(it1 != pr.end() && it1->first.first == u) {
      int begin = it1->first.first;
      int end = it1->first.second;
      int amount = it1->second;
      if(colors[end] == Color::White) {
        goal.insert({{end, begin}, amount});
      }
      ++it1;
    }
    auto it2 = p.lower_bound({u, 0});
    while(it2 != p.end() && it2->first.first == u) {
      int begin = it2->first.first;
      int end = it2->first.second;
      int amount = it2->second;
      if(colors[end] == Color::White) {
        goal.insert({{end, begin}, amount});
      }
      ++it2;
    }

    for(const auto& n : g[u].neighbours) {
      if(colors[n] == Color::White) {
        stack.push_back(n);
      }
    }
  }

  return g;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n, k;
  std::cin >> n >> k;

  Graph g(n);
  for(int i=1; i<n; ++i) {
    int u, v;
    std::cin >> u >> v;
    g[u-1].neighbours.push_back(v-1);
    g[v-1].neighbours.push_back(u-1);
  }

  Pumps pumps;
  Pumps pumpsReversed;
  for(int i=0; i<k; ++i) {
    std::pair<int, int> p;
    std::cin >> p.first >> p.second;
    p.first -= 1;
    p.second -= 1;
    if(p.first < p.second) {
      std::swap(p.first, p.second);
    }

    auto it = pumpsReversed.find(p);
    if(it == pumpsReversed.end()) {
      pumpsReversed[p] = 1;
    } else {
      it->second += 1;
    }

    std::swap(p.first, p.second);
    it = pumps.find(p);
    if(it == pumps.end()) {
      pumps[p] = 1;
    } else {
      it->second += 1;
    }
  }

  g = dfs(std::move(g), pumps, pumpsReversed);

  int max = 0;
  for(const auto& node : g) {
    max = std::max(node.flow, max);
  }

  std::cout << max << '\n';

  return 0;
}

