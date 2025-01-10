#include <cstdio>

int f(int n, int bound) {
    if (n <= 1 || bound <= 0) {
        return 0;
    } else {
        int ans = 0;
        for (int i = 1; i <= bound; i++) {
            ans += f(n - i, i);
            if (n - i > 0 && n - i <= i && n - i <= bound) {
                ans++;
            }
        }
        return ans;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", f(n, n - 1));
    return 0;
}