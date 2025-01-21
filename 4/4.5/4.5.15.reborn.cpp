#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000;
int n, m, a[MAXN], b[MAXN];

int getMax(int a[], int i, int b[], int j) {
    if (i < 0) {
        return b[j];
    }
    if (j < 0) {
        return a[i];
    }
    return max(a[i], b[j]);
}

int getMin(int a[], int i, int b[], int j) {
    if (i >= n) {
        return b[j];
    }
    if (j >= m) {
        return a[i];
    }
    return min(a[i], b[j]);
}

double binarySearch(int n, int a[], int m, int b[]) {
    int leftPartCount = (n + m + 1) / 2;
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        int j = leftPartCount - mid;
        if (a[mid - 1] > b[j]) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    if ((n + m) % 2) {
        return (double)getMax(a, l - 1, b, leftPartCount - l - 1);
    } else {
        return (getMax(a, l - 1, b, leftPartCount - l - 1) + getMin(a, l, b, leftPartCount - l)) / 2.0;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }
    if (n < m) {
        printf("%.1f", binarySearch(n, a, m, b));
    } else {
        printf("%.1f", binarySearch(m, b, n, a));
    }
    return 0;
}