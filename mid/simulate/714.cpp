#include <cstdio>

// 十进制转K进制（数组版）
int radix10ToK(int x, int K, int result[]) {
    int num = 0;    // 数组result存放K进制数的每一位，num为位数
    do {
        result[num++] = x % K;  // 除基取余
        x = x / K;              // x变为除以基的商
    } while(x);                 // 当商不为0时进行循环
    return num;                 // 返回K进制位数
}

int main() {
    int n, q;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &q);
        int d[20];
        int num = radix10ToK(q, 8, d);
        for (int j = num - 1; j >= 0; j--) {
            if (d[j] >= 5) {
                printf("%d", d[j] + 2);
            } else if (d[j] >= 2) {
                printf("%d", d[j] + 1);
            } else {
                printf("%d", d[j]);
            }
        }
        printf("\n");
    }
    return 0;
}//思路：八进制数，然后最后输出时候按位输出，