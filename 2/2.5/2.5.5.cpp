#include <cstdio>
#include <cstring>

const int MAXN = 10;
int a[MAXN];

int main() {
    int x;
    scanf("%d", &x);
    memset(a, x, sizeof(a));
    printf("%d", a[0]);
    return 0;
}