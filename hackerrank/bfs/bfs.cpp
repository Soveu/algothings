#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the bfs function below.
vector<int> bfs(const vector<vector<int>>& edges, int s) {
    std::vector<bool> visited(edges.size());
    std::vector<int> distances(edges.size(), -1);

    visited[s] = true;
    distances[s] = 0;

    std::queue<int> q;
    q.push(s);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v : edges[u]) {
            if(visited[v]) {
                continue;
            }

            visited[v] = true;
            distances[v] = distances[u] + 6;
            q.push(v);
        }
    }

    return distances;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n, m;
        std::cin >> n >> m;

        std::vector<std::vector<int>> g(n);
        for(int i=0; i<m; ++i) {
            int a, b;
            std::cin >> a >> b;
            g[a-1].push_back(b-1);
            g[b-1].push_back(a-1);
        }

        int s;
        std::cin >> s;
        s -= 1;

        const auto res = bfs(g, s);
        for(int res_it=0; res_it<res.size(); ++res_it) {
            if(res_it == s) {
                continue;
            }

            fout << res[res_it] << ' ';
        }
        fout << '\n';
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

