struct DisjoinSet {
  struct Item {
    int repr;
    int count;
  };

  std::vector<Item> vi;

  void init(size_t n) {
    this->vi.resize(n);
    size_t i=0;
    for(auto& x : this->vi) {
      x.repr = ++i;
      x.count = 1;
    }
  }

  int find(int x) {
    if(this->vi[x].repr == x) {
      return x;
    }

    return this->vi[x].repr = find(this->vi[x].repr);
  }

  void join(int _a, int _b) {
    Item* a = &(this->vi[this->find(_a)]);
    Item* b = &(this->vi[this->find(_b)]);

    if(a->count > b->count) {
      b->repr = a->repr;
      a->count += b->count;
    } else {
      a->repr = b->repr;
      b->count += a->count;
    }
  }
};

