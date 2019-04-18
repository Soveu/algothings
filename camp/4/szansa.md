Sposoby:
* brute (2 pętle + set)
* wyszukiwanie binarne na najmniejszą liczbę
* stworzenie sub-tablicy mnożenia
* taka "kolejka"

```
1: 1
2: 4,2
3: 9,6,3
4: 16,12,8,4
5: 25,20,15,10,5
   ^

set sortowany przez pozycje

set<int, Cmp> kol;
struct Cmp {
  bool operator()(int x, int y) {
    //~~return liczba[x] > liczba[y];~~
    if(liczba[x] != liczba[y]) {
      return liczba[x] > liczba[y];
    }

    return x > y;
  }
};

```
**najpierw wywalać elementy, później insertować**
lub
```

set<S>
struct S {
  //data
  bool operator<(S x, S y) {

  }
};
```

