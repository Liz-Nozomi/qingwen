#include <cstdio>
#include <queue>
using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    while (!q.empty()) {
        for (int i = 0; i < k - 1; i++) {
            int front = q.front();
            q.pop();
            q.push(front);
        }
        printf("%d", q.front());
        q.pop();
        if (!q.empty()) {
            printf(" ");
        }
    }
    return 0;
}