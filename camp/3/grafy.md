# Czy grafy są takie same?
graf = (zbiór wierzchołków, zbiór krawędzi)
G = (V, E)

G1 == G2 <=> v1 == v2 && permutacja etykiet wierzchołków

# Izomorfizm drzew
* ustalony korzeń
jak zignorować kolejność synów - hasze, sortowanie

h(v) = h(v1) + h(v2) + ... + h(vk)
h(liść) = 1

trzeba dobrać dobry korzeń - centroid
centroid = wierzchołek, po usunięciu którego rozmiar największej spójnej składowej <= n/2
dfs ukorzenia

ile(v) {
  w = 1
  visited[v] = true;
  for(x in adj[v]) {
    w += ile(x)
  }
}

wierzchołek jest centroidem jeżeli jego rozmiar poddrzewa jest \>n/2 i jego synów \<n/2

# SPROSTOWANIE
haszowanie jest złe w tym przypadku

h4 + s^a * h3 + s^a+b * h2 ...
lub
porównywanie/haszowanie posortowanych vectorów dzieci
map<vector<int>, int>

