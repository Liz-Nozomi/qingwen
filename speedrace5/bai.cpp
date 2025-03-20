#include <bits/stdc++.h>
using namespace std;

int minCut(string s) {
    int n = s.size();
    if (n == 0) return 0;

    vector<vector<bool> > is_palindrome(n, vector<bool>(n, false));
    //找i,j是不是回文

    for (int len = 1; len <= n; len++) {
        for (int i = 0; i + len <= n; i++) {
            int j = i + len - 1;
            if (len == 1) {
                is_palindrome[i][j] = true;
            } else if (len == 2) {
                is_palindrome[i][j] = (s[i] == s[j]);//i=j回文
            } else {
                is_palindrome[i][j] = (s[i] == s[j] and is_palindrome[i + 1][j - 1]);
            }
        }
    }
    vector<int> dp(n + 1, 0);//到第i个字符最小切分次数
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = i; // 最坏情况下，每个字符单独成回文
        for (int j = 0; j < i; j++) {
            if (is_palindrome[j][i - 1]) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }

    return dp[n];
}

int main() {
    string s;
    cin >> s;
    cout<<minCut(s);
}