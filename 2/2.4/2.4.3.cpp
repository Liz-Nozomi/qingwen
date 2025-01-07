#include <iostream>
using namespace std;
int main() {
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0) {
            continue;
        }
        sum += i;
    }
    printf("%d", sum);
    return 0;
}