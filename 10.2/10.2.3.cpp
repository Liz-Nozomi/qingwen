#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 100;
vector<int> G[MAXN];

int main() {
    int n, m, u, v;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        printf("%d(%d)", i, (int)G[i].size());
        for (int j = 0; j < G[i].size(); j++) {
            printf(" %d", G[i][j]);
        }
        printf("\n");
    }
    return 0;
}