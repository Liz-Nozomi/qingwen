#include <cstdio>

int main() {
    int numCase, a, b;
    scanf("%d", &numCase);
    while (numCase--)  {
        scanf("%d%d", &a, &b);
        printf("%d", a + b);
        if (numCase > 0) {
            printf("\n\n");
        }
    }
    return 0;
}