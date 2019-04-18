#include<iostream>
#include<stdio.h>
#include<vector>
#include<array>

#define BITSIZE 8

struct TrieEle {
  int child = 0;
  int count = 0;
};

using Int = unsigned long long;
using Trie = std::vector<std::array<TrieEle, 2>>;

Trie t;

void debug_tree() {
  for(int i=0; i<t.size(); ++i) {
    std::cout << i << ":\t[{" << t[i][0].child << ", " << t[i][0].count << "}, {"
      << t[i][1].child << ", " << t[i][1].count << "}]\n";
  }

  std::cout << "\n---------------------------\n";
}

void place_in_trie(Int x) {
  size_t node = 0;

  for(int i=0; i<BITSIZE; ++i) {
    if(t[node][x & 1].child == 0) {
      /* node doesnt exist, create one */
      t.push_back({0, 0});
      t[node][x & 1].child = t.size()-1;
      t[node][x & 1].count += 1;
    } else {
      /* node does exist */
      t[node][x & 1].count += 1;
    }

    node = t[node][x & 1].child;

    x >>= 1;
  }
}

Int run_mirror() {
  Int xored = 0;
  int left  = t[0][0].child;
  int right = t[0][1].child;

  for(int i=0; i<BITSIZE; ++i) {
    bool canLeftGoLeft = t[left][0].count > 0;
    bool canRightGoRight = t[right][1].count > 0;
    xored >>= 1;

    if(canLeftGoLeft && canRightGoRight) {
      /* mirror "outside" */
      left  = t[left][0].child;
      right = t[right][1].child;
      xored += (1ll<<BITSIZE);
    } else if(!canLeftGoLeft && !canRightGoRight) {
      /* mirror "inside" */
      left  = t[left][1].child;
      right = t[right][0].child;
      xored += (1ll<<BITSIZE);
    } else {
      /* go where you want */
      left  = t[left][!canLeftGoLeft].child;
      right = t[right][canRightGoRight].child;
    }
  }

  return xored;
}

int main() {
  int n;
  std::cin >> n;

  t.push_back({0,0});
  for(int i=0; i<n; ++i) {
    Int x;
    std::cin >> x;
    place_in_trie(x);
    debug_tree();
  }

  Int xored = run_mirror();

//  std::cout << xored << '\n';
  printf("%X\n", xored);

  return 0;
}

