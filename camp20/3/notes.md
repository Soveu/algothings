# Zbalansowana ścieżka
+-+-+-+
| | | |
+-+-+-+
| | | |
+-+-+-+

nie interesują nas obie liczby, tylko ich różnica
1,3 2,4
3,2 4,1
|
v
-2 -2
1  3

max = (MAXN + MAXM) * MAXA = (80 + 80) * 80 = 12800
dp[x][y][s]
s - suma <-12800; 12800>
x, y - współrzędne

dp[x][y][s] = 
dp[x-1][y][s - Axy] || dp[x-1][y][s + Axy] ||
dp[x][y-1][s - Axy] || dp[x][y-1][s + Axy]


# Przepływ
Spróbujmy rozwiązać to dla ścieżki
       v       v
       v   v
   o---o---o---o---o
1: 0   1   0   -1  0
2: 0   2   1   -1  -1
s: 0   2   2   1   0

HLD??? (niewzorcowe, niepotrzebne)


# Plik
co gdyby był tylko na 1 komputerze?
      4
     /|\
    1 3 0
   /  |
  0   2
     / \
    0   0

w pewnym miejscu 'zielony' plik będzie się zamieniał na 'niebieski'
wiedząc to miejsce można podzielić drzewo na 2 inne
wynik to max z tych dwóchh

wyszukać binarnie to miejsce

