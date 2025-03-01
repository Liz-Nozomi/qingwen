#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll memo[20][2][2][3];

string num;

ll dp(int pos,bool tight,bool leading_zero,int remainder){
    if(pos == num.size()){
        if(!leading_zero and remainder == 0){
            return 1;
        }else{
            return 0;
        }
    }

    if(memo[pos][tight][leading_zero][remainder] != -1){
        return memo[pos][tight][leading_zero][remainder];
    }

    ll res = 0;
    int limit = tight? (num[pos] - '0'):9;

    for(int d=0;d<=limit;d++){
        if(d == 3) continue;
        bool new_tight;
        if(tight and d == limit){
            new_tight = true;
        }
        else{
            new_tight = false;
        }


        bool new_leading_zero;
        if (leading_zero && d == 0) {
            new_leading_zero = true;
        } else {
            new_leading_zero = false;
        }

        // 更新余数
        int new_remainder;
        if (new_leading_zero) {
            new_remainder = remainder;
        } else {
            new_remainder = (remainder * 10 + d) % 3;
        }

        res += dp(pos + 1, new_tight, new_leading_zero, new_remainder);


    }    
    memo[pos][tight][leading_zero][remainder] = res;
    return res;

}

ll compute(string X) {
    num = X;
    // 初始化记忆化表为-1，表示尚未计算
    memset(memo, -1, sizeof(memo));
    // 递归计算，初始参数：
    // pos=0（从最高位开始），tight=true（初始受约束），leading_zero=true（初始前导零），remainder=0（初始余数）
    return dp(0, true, true, 0);
}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        ll L, R;
        cin >> L >> R;

        // 计算L-1，处理L=1的情况，此时L-1=0
        ll L_minus_1;
        if (L > 1) {
            L_minus_1 = L - 1;
        } else {
            L_minus_1 = 0;
        }

        // 将R和L-1转换为字符串形式
        string str_R = to_string(R);
        string str_L_minus_1 = to_string(L_minus_1);

        // 计算不超过R的满足条件的整数个数
        ll count_R = compute(str_R);

        // 计算不超过L-1的满足条件的整数个数
        ll count_L_minus_1;
        if (L_minus_1 >= 1) {
            count_L_minus_1 = compute(str_L_minus_1);
        } else {
            count_L_minus_1 = 0;
        }

        // 结果为区间内满足条件的整数个数
        cout << (count_R - count_L_minus_1) << "\n";
    }

    return 0;
}