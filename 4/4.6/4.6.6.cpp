#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 10000;
int n, a[MAXN];
int m, b[MAXN];
vector<int> unionSet;

void getUnionSet() {
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] == b[j]) {
            unionSet.push_back(a[i]);
            i++, j++;
        } else if (a[i] < b[j]) {
            unionSet.push_back(a[i++]);
        } else {
            unionSet.push_back(b[j++]);
        }
    }
    while (i < n) {
        unionSet.push_back(a[i++]);
    }
    while (j < m) {
        unionSet.push_back(b[j++]);
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
    getUnionSet();
    for (int i = 0; i < unionSet.size(); i++) {
        printf("%d", unionSet[i]);
        if (i < (int)unionSet.size() - 1) {
            printf(" ");
        }
    }
    return 0;
}