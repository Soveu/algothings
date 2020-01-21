#include <bits/stdc++.h>

struct Node {
    std::vector<int> neighbours;
    int parent;
    int value;
};
using Graph = std::vector<Node>;

struct DFSStruct {
    int vertex;
    int index;
};

Graph set_root(Graph g, int root) {
    std::vector<DFSStruct> stack;
    stack.push_back({root, static_cast<int>(g[root].neighbours.size())});

    while(!stack.empty()) {
        auto x = stack.back();

        if(x.index == 0) {
            int sum = 0;
            for(const auto& node : g[x.vertex].neighbours) {
                sum += (node == g[x.vertex].parent ? 0 : g[node].value);
            }
            g[x.vertex].value = sum+1;
            stack.pop_back();
            continue;
        }
        x.index -= 1;

        if(g[x.vertex].neighbours[x.index] == g[x.vertex].parent) {
            if(x.index == 0) {
                int sum = 0;
                for(const auto& node : g[x.vertex].neighbours) {
                    sum += (node == g[x.vertex].parent ? 0 : g[node].value);
                }
                g[x.vertex].value = sum+1;
                stack.pop_back();
                continue;
            }
            x.index -= 1;
        }

        int p = g[x.vertex].neighbours[x.index];
        g[p].parent = x.vertex;
        stack.back() = x;
        stack.push_back({p, static_cast<int>(g[p].neighbours.size())});
    }

    return g;
}

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;
    Graph g(n);

    for(int i=0; i<m; ++i) {
        int u, v;
        std::cin >> u >> v;
        assert(u <= n && v <= n);
        g[u-1].neighbours.push_back(v-1);
        g[v-1].neighbours.push_back(u-1);
    }
    for(const auto& node : g) {
        std::cout << node.parent << ' ';
    }
    std::cout << std::endl;

    g = set_root(std::move(g), 0);
    g[0].parent = -1;
    for(const auto& node : g) {
        std::cout << node.value << ' ';
    }
    std::cout << '\n';
}
