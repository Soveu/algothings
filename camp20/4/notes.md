# Działka
1 3 4 1
2 3 2 6
9 5 3 4
7 2 3 8

## I rozwiązanie
### Pierwsza tablica

1  4  8  9
3
12
19

dp[x][y] = dp[x-1][y] + dp[x][y-1] + tab[x][y]

### Druga tablica

19
18
16
7

### Trzecia tablica

dp[x][y] = dp[x-1][y+1] + dp[x+1][y-1] ...

? ? ?

## II rozwiązanie
+-+
| +-+
|   +-+
|   | +-+
|---+---+-+
|   |     +-+
+-----------+

# Tunele
## I sposób (subtask 10N)
DZIELENIE NA KUBECZKI (po 16-17)

## II sposób
checkpointy w odległości sqrt(n)
połącz punkty pomiędzy checkpointami do checkpointów
ale nie można się dostać pomiędzy punktami w jednym kubełku
rekursywna aplikacja w kubełkach
później rozmiar takich kubełków wynosi 5, więc można to zrobić na "piechotę"

## III sposób
MOST
dzielenie na 3, rekursywna aplikacja
wszystkie po lewej do lewego 'słupka', nieparzyste ze środka do lewego,
parzyste ze środka do prawego, wszystkie z prawego do prawego

# Zdjęcie
5 permutacji na wejściu (przemieszane)
jeżeli w oryginalnym ciągu było a, b to w wymieszanym co najmniej 3 razy tak będzie
tablica odwrotna (tab[x] = i)
sort z customowym porównywaniem
```cpp
bool cmp(int a, int b) {
  int x = 0;
  for(int i=0; i<5; ++i) {
    x += (tab[i][a] < tab[i][b]);
  }
  return x >= 3;
}
```

## II podejście (losowe)
x = random.choice(tab)

