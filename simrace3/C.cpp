#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> attack(n);
    for (int i = 0; i < n; i++) {
        cin >> attack[i];
    }

    // dp[pos][num] 表示当前攻击位置是 pos，已选攻击次数是 num 时的最大奖励
    vector<vector<int>> dp(n + 1, vector<int>(4, 0)); // num 只有 0, 1, 2, 3 四种状态

    for (int pos = n - 1; pos >= 0; --pos) {
        for (int num = 0; num < 3; ++num) {
            // 不选当前攻击
            dp[pos][num] = max(dp[pos][num], dp[pos + 1][num]);
            // 选当前攻击，num = 0, 1, 2分别对应不同的奖励
            int nextMoney = (num + 1) % 3 == 0 ? attack[pos] * 3 : attack[pos];
            dp[pos][num] = max(dp[pos][num], dp[pos + 1][(num + 1) % 3] + nextMoney);
        }
    }

    cout << dp[0][0] << endl; // 从起点开始，num = 0时的最大奖励
    return 0;
}
