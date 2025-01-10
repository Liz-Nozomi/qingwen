#include <cstdio>
#include <algorithm>
using namespace std;

int f(int n) {
    if (n == 1) {
        return 1;
    } else {
        int maxProduct = 1;
        for (int i = 1; i < n; i++) {
            maxProduct = max(maxProduct, max(f(n - i), n - i) * i);
        }
        return maxProduct;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", f(n));
    return 0;
}