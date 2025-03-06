#include <iostream>
#include <string>
using namespace std;
const int MAXN = 10001;
#define lowbit(i) ((i)&(-i))
int c[MAXN] = {0};

void update(int x, int v) {
    for (int i = x; i < MAXN; i += lowbit(i)) {
        c[i] += v;
    }
}

int getSum(int x) {
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        sum += c[i];
    }
    return sum;
}

int main() {
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        cout << getSum(x - 1) << (i < n - 1 ? " " : "\n");
        //核心就这一行 插入X 然后输出query(x-1)
        update(x, 1);
    }
    return 0;
}