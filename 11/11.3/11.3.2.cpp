#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100;
int a[MAXN];
int dp[MAXN], pre[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    memset(pre, -1, sizeof(pre));
    int k, maxLen = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] <= a[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                pre[i] = j;
            }
        }
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            k = i;
        }
    }
    vector<int> maxLenSeq;
    while (k != -1) {
        maxLenSeq.push_back(a[k]);
        k = pre[k];
    }
    reverse(maxLenSeq.begin(), maxLenSeq.end());
    printf("%d\n", maxLen);
    for (int i = 0; i < maxLenSeq.size(); i++) {
        printf("%d", maxLenSeq[i]);
        if (i < (int)maxLenSeq.size() - 1) {
            printf(" ");
        }
    }
    return 0;
}
//每一次进行转移时，把上一个path[j] push_back上i，然后存储到path[i]