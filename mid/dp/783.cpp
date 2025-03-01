#include <bits/stdc++.h>
using namespace std;


int f(int n, int *a, int *b) {
    vector<int> dp(n,-1);
    dp[n-1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        int nextA = -1;
        int nextB = -1;

        if (i + a[i] < n) {
            nextA = dp[i + a[i]];
        }
        if (i + b[i] < n) {
            nextB = dp[i + b[i]];
        }

        if (nextA != -1 && nextB != -1) {
            if (nextA < nextB) {
                dp[i] = nextA + 1;
            } else {
                dp[i] = nextB + 1;
            }
        } else if (nextA != -1) {
            dp[i] = nextA + 1;
        } else if (nextB != -1) {
            dp[i] = nextB + 1;
        }
    }
    return dp[0];

}

int main() {
    int n;
    scanf("%d", &n);

    int* a = (int*)malloc((n-1) * sizeof(int));
    int* b = (int*)malloc((n-1) * sizeof(int));
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &b[i]);
    }
    
    printf("%d", f(n, a, b));
    return 0;
}