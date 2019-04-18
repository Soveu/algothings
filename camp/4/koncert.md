Sposoby
* brute
* zoptymalizowany brute
* mutliset (n log k)
* algorytm z kwiatków
* sparse table

```cpp
min[x][s]   = min(t[x], t[x+1], .. , t[x+2^s-1])
min[x][s+1] = min(min[x][s], min[s+2^s][s])
```

* wzorcowe - złożoność liniowa
Minimum w okienku

```cpp
add_right()
delete_left()
min_range()
```

dwustronna kolejka pary (element, pozycja)
**DEQUE**

przykład
```
5 7 3  7 4 8
(5; 1)
(7; 2)
(3; 3) - nowe minimum najbardziej na prawo
```

