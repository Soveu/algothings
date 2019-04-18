#include <vector>
#include <iostream>
#include <stdio.h>

#define BITSIZE 62

struct Node {
  int count = 0;
  int child[2]{0, 0};
};

using Int = unsigned long long;
using Trie = std::vector<Node>;

Trie t;

void debug_trie() {
  for(int i=0; i<t.size(); ++i) {
    printf("%d:\t{count: %0d, child: [%0d, %0d]}\n", 
        i, t[i].count, t[i].child[0], t[i].child[1]);
  }

  printf("\n---------------------------\n");
}

void place_in_trie(Int x) {
  int node = 0;

  for(int i=0; i<BITSIZE; ++i) {
    if(t[node].child[x & 1] == 0) {
      /* create child if it doesnt exist */
      t.push_back(Node{});
      t[node].child[x & 1] = t.size()-1;
    }

    node = t[node].child[x & 1];
    t[node].count += 1;
    x >>= 1;
  }
}

Int run_mirror() {
  Int xored = 0;
//  int left  = t[0].child[0];
//  int right = t[0].child[1];
  int left = 0;
  int right = 0;

  for(int i=0; i<BITSIZE; ++i) {
    int llCount = t[t[left].child[0]].count;
    int lrCount = t[t[left].child[1]].count;
    int rlCount = t[t[right].child[0]].count;
    int rrCount = t[t[right].child[1]].count;

    //printf("llCount = %d, lrCount = %d, rlCount = %d, rrCount = %d ",
    //    llCount, lrCount, rlCount, rrCount);

    long long possibOutside = llCount * rrCount;
    long long possibInside  = lrCount * lrCount;

    /* ------------------- TODO ---------------------- */
    /* to nie znajduje zawsze dobrej odpowiedzi - dfs? */
    if(possibOutside == 0 && possibInside == 0) {
      if(llCount > 0 && rlCount > 0) {
        left = t[left].child[0];
        right = t[right].child[0];
      } else {
        left = t[left].child[1];
        right = t[right].child[1];
      }
    } else if(possibOutside > possibInside) {
      left = t[left].child[0];
      right = t[right].child[1];
      xored += (1ll << BITSIZE);
    } else {
      left = t[left].child[1];
      right = t[right].child[0];
      xored += (1ll << BITSIZE);
    }

    xored >>= 1;
    //printf("\n");
  }

  return xored;
}

int main() {
  t.push_back(Node{});

  int n;
  std::cin >> n;

  for(int i=0; i<n; ++i) {
    Int x;
    std::cin >> x;
    place_in_trie(x);
  }

//  debug_trie();
  std::cout << run_mirror() << '\n';

  //printf("%X\n", xored);
}

