#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000;
const int INF = 1e9;
int n, a[MAXN];
int prefixSum[MAXN] = {0};

int getPrefixSum(int i) {
    if (i >= 0 && i < n) {
        return prefixSum[i];
    } else {
        return 0;
    }
}

int main() {
    scanf("%d", &n);
    int oneCnt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        oneCnt += a[i];
        if (i == 0) {
            prefixSum[i] = a[i];
        } else {
            prefixSum[i] = prefixSum[i - 1] + a[i];
        }
    }
    int minRes = INF;
    for (int i = 0; i < n; i++) {
        minRes = min(minRes, oneCnt - (getPrefixSum(i + oneCnt - 1) - getPrefixSum(i - 1)));
    }
    printf("%d", minRes);
    return 0;
}