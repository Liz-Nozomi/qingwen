#include <bits/stdc++.h>
using namespace std;

int max_safe_dist(vector<int>& tree, vector<int>& trap) {
    sort(trap.begin(), trap.end());  // 确保陷阱数组是有序的
    int maxd = 0;
    for (auto it : tree) {
        auto pos = lower_bound(trap.begin(), trap.end(), it);
        int mindist = INT_MAX;
        if (pos != trap.end()) {
            mindist = *pos - it;
        }
        if (pos != trap.begin()) {
            int leftdist = it - *(pos - 1);
            mindist = min(mindist, leftdist);
        }
        if (mindist > maxd) {
            maxd = mindist;
        }
    }
    return maxd;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> tree(n);
    for (int i = 0; i < n; ++i) {
        cin >> tree[i];
    }
    vector<int> trap(m);
    for (int i = 0; i < m; ++i) {
        cin >> trap[i];
    }
    cout << max_safe_dist(tree, trap) << endl;
    return 0;
}