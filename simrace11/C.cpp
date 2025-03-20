#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 105;
const int MAX_X = 10005;

bool dp[MAX_N][MAX_X];  // 记录是否可达
vector<string> paths[MAX_N][MAX_X];  // 记录所有路径

int main() {
    ios::sync_with_stdio(false);


    int N, X;
    cin >> N >> X;
    vector<pair<int, int> > jumps(N + 1);

    vector<int> maxd(N+1);
    vector<int> mind(N+1);
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
    paths[0][0].push_back("");  // 初始路径为空


    for (int i = 1; i <= N; ++i) {

        int ci = jumps[i].first, di = jumps[i].second;

        for (auto j:possibledist[i-1]) {

            if (dp[i - 1][j]) {  // 如果上一步可以到达
                // 选 ci
                if (j + ci <= X) {
                    dp[i][j + ci] = true;
                    for (const string& path : paths[i - 1][j]) {
                        paths[i][j + ci].push_back(path + 'a');
                    }
                }
                // 选 di
                if (j + di <= X) {
                    dp[i][j + di] = true;
                    for (const string& path : paths[i - 1][j]) {
                        paths[i][j + di].push_back(path + 'b');
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
    sort(paths[N][X].begin(), paths[N][X].end());
    for (const string& path : paths[N][X]) {
        cout << path << endl;
        break;
    }
    return 0;
}