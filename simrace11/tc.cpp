#include <iostream>
#include <vector>
#include<algorithm>
#include <cstring>
using namespace std;

const int MAX_N = 105;
const int MAX_X = 10005;

bool dp[MAX_N][MAX_X];  // 记录是否可达
vector<string> paths[MAX_N][MAX_X];  // 记录所有路径

int main() {
    int N, X;
    cin >> N >> X;
    vector<pair<int, int> > jumps(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> jumps[i].first >> jumps[i].second;
    }
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;
    paths[0][0].push_back("");  // 初始路径为空
    // DP 计算可达性并存储路径
    for (int i = 1; i <= N; ++i) {
        int ci = jumps[i].first, di = jumps[i].second;
        for (int j = 0; j < MAX_X; ++j) {
            if (dp[i - 1][j]) {  // 如果上一步可以到达
                // 选 ci
                if (j + ci < MAX_X) {
                    dp[i][j + ci] = true;
                    for (const string& path : paths[i - 1][j]) {
                        paths[i][j + ci].push_back(path + 'a');
                    }
                }
                // 选 di
                if (j + di < MAX_X) {
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

