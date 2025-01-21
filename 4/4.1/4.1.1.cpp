#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 50;
int a[MAXN], n;

void selectSort() {
    for (int i = 0; i < n; i++) {
        int k = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[k]) {
                k = j;
            }
        }
        swap(a[i], a[k]);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    selectSort();
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        printf(i < n - 1 ? " " : "\n");
    }
    return 0;
}