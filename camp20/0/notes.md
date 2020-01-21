### Acyklizacja

lista wierzchołków - [1,2,3,4,...]
krawędzie "w prawo" i "w lewo" dfsem

### Zbiory

## 1
graf - n wierzchołków
DP - 2 stany (bierzemy wierzchołek albo nie)
`dp[v][1] = sum(dp[u][0]) + 1 # u - dzieci`
`ans = max(dp[v][1])`
to tylko działa na drzewach (n-1 krawędzi)

## 2
???

### Tasowanie

parzysta lub nieparzysta - nakładają się obie czy nie
`a*b*a*b*...*a*b=(a*b)^k`
cykle

`a*b*a*b*...*a*b*a=a * (a*b)^k` /a
`a*b*a*b*...*a*b=(a*b)^k`

równanie z wieloma warunkami
chińskie twierdzenie o resztach???

odwrotność permutacji
`for(0, n-1) b[a[i]] = i`

