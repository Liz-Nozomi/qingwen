#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100;
int a[MAXN];
int dp[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] <= a[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        maxLen = max(maxLen, dp[i]);
    }
    printf("%d", maxLen);
    return 0;
}