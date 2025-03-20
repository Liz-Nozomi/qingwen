#include <bits/stdc++.h>
using namespace std;

vector<long long> t5nums;
vector<pair<int, int> > ranges;

void generate_35_nums(int len, string s, int sz) {
    if (len == sz) {
        t5nums.push_back(stoll(s));
        return;
    }
    generate_35_nums(len + 1, s + '3', sz);
    generate_35_nums(len + 1, s + '5', sz);
}

bool isvalid(int l, int r, int k) {
    long long left = t5nums[l];
    long long right = t5nums[r];
    int opcnt = 0;
    for (auto it : ranges) {
        int itl = it.first;
        int itr = it.second;
        // 计算将输入区间 [itl, itr] 调整到 [left, right] 所需的操作数
        opcnt += max(left - itl, itr - right);
        if (opcnt > k) break; // 提前终止，避免无效计算
    }
    return opcnt <= k;
}

int main() {
    int n, k;
    cin >> n >> k;

    // 生成所有可能的3和5组成的数字
    for (int sz = 1; sz <= 12; sz++) {
        generate_35_nums(0, "", sz);
    }
    sort(t5nums.begin(), t5nums.end());
    t5nums.erase(unique(t5nums.begin(), t5nums.end()), t5nums.end()); // 去重

    // 读取输入区间
    for (int i = 0; i < n; i++) {
        int lf, rt;
        cin >> lf >> rt;
        ranges.push_back(make_pair(lf, rt));
    }

    int max_len = 0;
    int l = 0;
    for (int r = 0; r < t5nums.size(); r++) {
        while (l <= r && !isvalid(l, r, k)) {
            l++;
        }
        if (l <= r) {
            max_len = max(max_len, r - l + 1);
        }
    }

    cout << max_len << endl;

    return 0;
}