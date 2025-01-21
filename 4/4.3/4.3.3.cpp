#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100;      // 最大元素个数
int a[MAXN];               // 存放元素的数组
// 求到下标i为止的序列最大值
int findMax(int i) {
    if (i == 0) {          // 如果到下标0为止
        return a[0];       // 那么直接返回第一个元素
    } else {
        // 其他情况返回到下标i-1为止的最大值与a[i]的较大值
        return max(findMax(i - 1), a[i]);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {       // 输入序列元素，下标从0开始
        scanf("%d", &a[i]);
    }
    printf("%d\n", findMax(n - 1));    // 最终结果为到下标n-1为止
    return 0;
}