#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 100 + 1;
int dp[MAXN][MAXN];

int main() {
    string s, t;
    cin >> s >> t;
    for (int i = 0; i <= s.length(); i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= t.length(); j++) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= s.length(); i++) {
        for (int j = 1; j <= t.length(); j++) {
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s[i - 1] == t[j - 1] ? 0 : 1));
        }
    }
    cout << dp[s.length()][t.length()];
    return 0;
}