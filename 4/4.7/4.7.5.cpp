#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n, x, leftMax = 0;
    scanf("%d", &n);
    int result = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x > leftMax) {
            result++;
        }
        leftMax = max(leftMax, x);
    }
    printf("%d", result);
    return 0;
}