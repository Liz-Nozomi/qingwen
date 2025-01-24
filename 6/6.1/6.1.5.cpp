#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n, x, k1, k2;
    scanf("%d", &n);
    vector<int> v;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        v.push_back(x);
    }
    scanf("%d%d%d", &x, &k1, &k2);
    v.insert(v.begin() + k1, x);
    v.erase(v.begin() + k2);
    for (int i = 0; i < (int)v.size(); i++) {
        printf("%d", v[i]);
        if (i < (int)v.size() - 1) {
            printf(" ");
        }
    }
    return 0;
}