
#include <cstdio>

const int MAXN = 1000;
int n, a[MAXN];
int merged[MAXN];

void merge(int l1, int r1, int l2, int r2) {
    int i = l1, j = l2, cnt = 0;
    while (i <= r1 && j <= r2) {
        if (a[i] < a[j]) {
            merged[cnt++] = a[i++];
        } else {
            merged[cnt++] = a[j++];
        }
    }
    while (i <= r1) {
        merged[cnt++] = a[i++];
    }
    while (j <= r2) {
        merged[cnt++] = a[j++];
    }
    for (i = 0; i < cnt; i++) {
        a[l1 + i] = merged[i];
    }
}

void mergeSort(int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(l, mid);
        mergeSort(mid + 1, r);
        merge(l, mid, mid + 1, r);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    mergeSort(0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    return 0;
}