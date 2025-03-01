#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//一年都不一定写得对的
string num_str;
// 备忘录，用于记忆化搜索
ll memo_cache[20][2][2][2][2];
// 数字的总位数
int total_digits;

ll dp(int pos, int tight, int has1, int has9, int has_started){
    // 如果已经处理完所有位
    if(pos == total_digits){
        // 如果已经开始且同时包含1和9，返回1，否则返回0
        return (has_started && has1 && has9) ? 1 : 0;
    }
    // 如果当前状态已经计算过，直接返回结果
    if(memo_cache[pos][tight][has1][has9][has_started] != -1){
        return memo_cache[pos][tight][has1][has9][has_started];
    }
    // 确定当前位的上限
    int limit = tight ? (num_str[pos] - '0') : 9;
    ll res = 0;
    // 遍历当前位可以选择的数字
    for(int d = 0; d <= limit; d++){
        // 更新tight状态：如果当前位取d且d等于上限，则下一位仍然受限
        int new_tight = tight && (d == limit) ? 1 : 0;
        // 更新是否已经开始处理有效数字
        int new_has_started = has_started || (d != 0) ? 1 : 0;
        // 更新has1和has9状态
        int new_has1 = has1;
        int new_has9 = has9;
        if(new_has_started){
            if(d == 1) new_has1 = 1; // 如果当前位是1，标记has1为真
            if(d == 9) new_has9 = 1; // 如果当前位是9，标记has9为真
        }
        // 递归处理下一位
        res += dp(pos + 1, new_tight, new_has1, new_has9, new_has_started);
    }
    // 将结果存入备忘录
    return memo_cache[pos][tight][has1][has9][has_started] = res;
}

/**
 * 计算不超过x的符合条件的数字个数
 * @param x 上界数字
 * @return 符合条件的数字个数
 */
ll count_numbers(ll x){
    if(x < 1) return 0; // 如果x小于1，直接返回0
    num_str = to_string(x); // 将数字转换为字符串
    total_digits = num_str.size(); // 获取数字的位数
    // 初始化备忘录为-1，表示未计算
    memset(memo_cache, -1, sizeof(memo_cache));
    // 调用DP函数从第0位开始，初始状态为紧束、未出现1和9、未开始处理
    return dp(0, 1, 0, 0, 0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n; // 输入查询的数量
    while(n--){
        ll L, R;
        cin >> L >> R; // 输入每个查询的区间[L, R]
        // 计算不超过R的符合条件的数字个数
        ll count_R = count_numbers(R);
        // 计算不超过L-1的符合条件的数字个数
        ll count_L_minus_1 = count_numbers(L - 1);
        // 区间[L, R]内的符合条件的数字个数为count_R - count_L_minus_1
        ll result = count_R - count_L_minus_1;
        cout << result << "\n"; // 输出结果
    }
    return 0;
}