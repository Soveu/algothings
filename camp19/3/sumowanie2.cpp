#include<iostream>

using Int = long long;

struct Req {
  int id;
  int range;
};

bool comparator(const Req& a, const Req& b) {
  return a.range > b.range;
}

Int wyniki[100000];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int d, p;
  std::cin >> d >> p;

  int q;
  std::cin >> q;

  std::vector<Req> requests(q);
  for(int i=1; i<=q; i+=2) {
    std::cin >> requests[i].range >> requests[i+1].range;
    requests[i].id = -i;
    requests[i+1].id = i;
  }

  std::sort(requests.begin(), requests.end(), comparator);

  for(const auto& r : requests) {
    if(r.id < 0) {
      wyniki[-r.id] -= TODO;
    } else {
      wyniki[r.id]  += TODO;
    }
  }

  return 0;
}

