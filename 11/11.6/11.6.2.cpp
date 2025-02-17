#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100;
const int INF = 1e9;
int G[MAXN][MAXN];
int dp[MAXN];
int choice[MAXN];

int getDAGMaxLength(int i, int n) {
    if (dp[i]) {
        return dp[i];
    }
    for (int j = 0; j < n; j++) {
        if (G[i][j] != INF) {
            int newLength = getDAGMaxLength(j, n) + G[i][j];
            if (newLength > dp[i]) {
                dp[i] = newLength;
                choice[i] = j;
            }
        }
    }
    return dp[i];
}

int main() {
    memset(dp, 0, sizeof(dp));
    memset(choice, -1, sizeof(choice));
    fill(G[0], G[0] + MAXN * MAXN, INF);
    int n, m;
    scanf("%d%d", &n, &m);
    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        G[u][v] = w;
    }
    int k, maxLength = 0;
    for (int i = 0; i < n; i++) {
        int tempLength = getDAGMaxLength(i, n);
        if (tempLength > maxLength) {
            maxLength = tempLength;
            k = i;
        }
    }
    while (k != -1) {
        printf("%d", k);
        k = choice[k];
        if (k != -1) {
            printf("->");
        }
    }
    return 0;
}