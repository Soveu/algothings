#include<iostream>
#include<deque>

struct Item {
  int ele;
  int pos;
};

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  std::deque<Item> minq;
  std::deque<Item> maxq;

  int n, k;
  std::cin >> n >> k;

  Item tmp{0, 0};
  std::cin >> tmp.ele;
  minq.push_back(tmp);
  maxq.push_back(tmp);

  int deltaMax = 0;

  /* może jednak .clear() ? */
  tmp.pos++;
  while(tmp.pos < n) {
    if(tmp.pos - minq.front().pos == k + 1) {
      minq.pop_front();
    }
    if(tmp.pos - maxq.front().pos == k + 1) {
      maxq.pop_front();
    }

    std::cin >> tmp.ele;

    while(minq.size() > 0 && minq.back().ele > tmp.ele) {
        minq.pop_back();
    }
    minq.push_back(tmp);

    while(maxq.size() > 0 && maxq.back().ele < tmp.ele) {
      maxq.pop_back();
    }
    maxq.push_back(tmp);

    deltaMax = std::max(deltaMax, 
        maxq.front().ele - minq.front().ele);

    tmp.pos++;
  }

  std::cout << deltaMax << '\n';

  return 0;
}

