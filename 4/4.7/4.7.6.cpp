#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 100000000;
const int MAXN = 100000;
int a[MAXN];
int leftMax[MAXN];

int main() {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (i == 0) {
            leftMax[i] = a[i];
        } else {
            leftMax[i] = max(leftMax[i - 1], a[i]);
        }
    }
    int rightMin = INF, result = 0;
    for (int i = n - 1; i >= 0; i--) {
        if ((i == 0 || leftMax[i - 1] < a[i]) && a[i] < rightMin) {
            result++;
        }
        rightMin = min(rightMin, a[i]);
    }
    printf("%d", result);
    return 0;
}