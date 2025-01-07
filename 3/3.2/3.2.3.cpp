
#include <cstdio>

const int MAXN = 1024;
int a[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int k, cnt = 0;
    scanf("%d", &k);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] + a[j] == k) {
                cnt++;
            }
        }
    }
    printf("%d", cnt);
    return 0;
}