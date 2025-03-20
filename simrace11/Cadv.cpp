#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 105;
const int MAX_X = 10005;

bool dp[MAX_N][MAX_X];  // 记录是否可达
string paths[MAX_N][MAX_X];  // 记录单条路径

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X;
    cin >> N >> X;
    vector<pair<int, int>> jumps(N + 1);

    vector<int> maxd(N + 1), mind(N + 1);
    set<int> possibledist[MAX_N];
    possibledist[0].insert(0);

    for (int i = 1; i <= N; ++i) {
        cin >> jumps[i].first >> jumps[i].second;
        for(auto it:possibledist[i-1]){
            possibledist[i].insert(it+jumps[i].first);
            possibledist[i].insert(it+jumps[i].second);
        }
    }

    memset(dp, false, sizeof(dp));
    dp[0][0] = true;
    paths[0][0] = "";  // 初始路径为空

    for (int i = 1; i <= N; ++i) {
        int ci = jumps[i].first, di = jumps[i].second;
        for (auto j:possibledist[i-1]) {
            if (dp[i - 1][j]) {
                // 优先选择 'a'
                if (j + ci <=X ) {
                    if (!dp[i][j + ci] || paths[i][j + ci] > paths[i - 1][j] + 'a') {
                        dp[i][j + ci] = true;
                        paths[i][j + ci] = paths[i - 1][j] + 'a';
                    }
                }
                // 再选择 'b'
                if (j + di <=X) {
                    if (!dp[i][j + di] || paths[i][j + di] > paths[i - 1][j] + 'b') {
                        dp[i][j + di] = true;
                        paths[i][j + di] = paths[i - 1][j] + 'b';
                    }
                }
            }
        }
    }

    if (!dp[N][X]) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    cout << paths[N][X] << endl;

    return 0;
}