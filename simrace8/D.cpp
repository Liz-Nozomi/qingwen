#include <bits/stdc++.h>

using namespace std;

const int maxn = 410;

struct Edge {
    int to;
    char c;
    Edge(int t, char ch) : to(t), c(ch) {}
};
vector<Edge> adj[maxn];   
bool has_edge[maxn][maxn]; 
int f[maxn][maxn];         // dp
queue<pair<int, int> > q;

int main() {
    int n, m;
    cin >> n >> m;

    memset(has_edge, false, sizeof(has_edge));

    for (int i = 0; i < m; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
        has_edge[a][b] = true;
        has_edge[b][a] = true;
    }
    //无向图

    memset(f, -1, sizeof(f));

    for (int i = 0; i < n; ++i) {
        f[i][i] = 0;
        q.push(make_pair(i, i));
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && has_edge[i][j]) {
                f[i][j] = 1;
                q.push(make_pair(i,j));
            }
        }
    }

    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        int a = u.first;
        int b = u.second;
        int current = f[a][b];

        for (char x = 'a'; x <= 'z'; x++) {
            vector<Edge> &edges_a = adj[a];
            vector<Edge> &edges_b = adj[b];

            for (auto e : edges_a) {
                if (e.c == x) {
                    int i = e.to;
                    for (auto e2 : edges_b) {
                        if (e2.c == x) {
                            int j = e2.to;
                            if (f[i][j] == -1 or f[i][j] > current + 2) {
                                f[i][j] = current + 2;
                                q.push(make_pair(i,j));
                            }
                        }
                    }
                }
            }
        }
    }

    cout << (f[0][n-1] == -1 ? -1 : f[0][n-1]) << endl;

    return 0;
}