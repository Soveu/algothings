#include <iostream>
#include <stdint.h>

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
  std::vector<bool> visited(g.size());
  /* map end of pump -> begin and amount */
  std::multimap<int, Pump> goal;
  std::vector<std::pair<int, bool>> stack;

  stack.push_back({0, false});
  while(!stack.empty()) {
    auto x = stack.back();
    int u = x.first;
    bool working = x.second;

    stack.pop_back();
    visited[u] = true;
    
    if(working == false) {
      stack.push_back({u, true});
    } else {
      continue;
    }

    auto it = goal.lower_bound(u);
    auto begin = it;
    //auto end = goal.upper_bound(u);
    while(it != goal.end() && it->first == u) {
      int dest = it->second.end;
      int amount = it->second.amount;
      for(auto i=stack.rbegin(); i != stack.rend(); ++i) {
        g[i->first].flow += amount;
        if(i->first == dest) break;
      }
      ++it;
    }
    goal.erase(begin, it);

    auto it1 = pr.lower_bound({u, 0});
    while(it1 != pr.end() && it1->first.first == u) {
      int begin = it1->first.first;
      int end = it1->first.second;
      int amount = it1->second;
      if(!visited[end]) {
        goal.insert({end, Pump{begin, amount}});
      }
      ++it1;
    }
    auto it2 = p.lower_bound({u, 0});
    while(it2 != pr.end() && it2->first.first == u) {
      int begin = it2->first.first;
      int end = it2->first.second;
      int amount = it2->second;
      if(!visited[end]) {
        goal.insert({end, Pump{begin, amount}});
      }
      ++it2;
    }

    for(const auto& n : g[u].neighbours) {
      if(!visited[n]) {
        stack.push_back({n, false});
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

