#include <bits/stdc++.h>
using namespace std;
#define int long long
struct med {
    int v; // 药物价值
    int l; // 最小消耗
    int r; // 最大消耗
};

const int INF = numeric_limits<int>::min();
#undef int
int main() {
#define int long long
    int n, w;
    cin >> n >> w;

    vector<med> meds(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> meds[i].l >> meds[i].r >> meds[i].v;
    }

    // 检查是否所有药物的最小消耗总和超过 w
    int sum_l = 0;
    for (int i = 1; i <= n; i++) {
        sum_l += meds[i].l;
    }
    if (sum_l > w) {
        cout << "-1 -1" << endl;
        return 0;
    }

    int dp_val[305][305]; // 记录最大价值
    int dp_cnt[305][305]; // 记录对应种类数
    for (int i = 0; i <= n; i++) {
        fill(dp_val[i], dp_val[i] + 305, INF);
        fill(dp_cnt[i], dp_cnt[i] + 305, n + 1); // 初始化为不可能的大数
    }
    dp_val[0][0] = 0;
    dp_cnt[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (dp_val[i-1][j] == INF) continue;

            // 必须选择当前药物
            for (int c = meds[i].l; c <= meds[i].r; c++) {
                int new_j = j + c;
                if (new_j > w) continue;

                int new_val = dp_val[i-1][j] + meds[i].v;
                int new_cnt = dp_cnt[i-1][j] + 1;

                if (new_val > dp_val[i][new_j]) {
                    dp_val[i][new_j] = new_val;
                    dp_cnt[i][new_j] = new_cnt;
                } else if (new_val == dp_val[i][new_j]) {
                    dp_cnt[i][new_j] = min(dp_cnt[i][new_j], new_cnt);
                }
            }
        }
    }

    // 输出结果
    if (dp_val[n][w] != INF && dp_cnt[n][w] == n) {
        cout << dp_val[n][w] << " " << dp_cnt[n][w] << endl;
    } else {
        cout << "-1 -1" << endl;
    }

    return 0;
}