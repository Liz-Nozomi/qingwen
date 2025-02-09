#include <cstdio>
#include <cstring>

const int MAXN = 100;
int father[MAXN];

int findFather(int x) {
    int xCopy = x;
    while (father[x] != x) {
        x = father[x];
    }
    int root = x;
    x = xCopy;
    while (father[x] != x) {
        int fatherX = father[x];
        father[x] = root;
        x = fatherX;
    }
    return root;
}

void unionSet(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB) {
        father[faA] = faB;
    }
}

void init(int n) {
    for (int i = 0; i < n; i++) {
        father[i] = i;
    }
}

int main() {
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    init(n);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        unionSet(a - 1, b - 1);
    }
    int classCount = 0;
    for (int i = 0; i < n; i++) {
        if (father[i] == i) {
            classCount++;
        }
    }
    printf("%d", classCount);
    return 0;
}