#include <bits/stdc++.h>
using namespace std;

// 将整数转换为二进制位并存储在vector中（不反转顺序）
vector<int> int_to_bit(int n) {
    vector<int> bits(32, 0);
    for (int i = 0; i < 32; ++i) {
        bits[i] = (n >> i) & 1;
    }
    return bits;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    // 获取k的二进制位
    vector<int> k_bit = int_to_bit(k);
    
    // 获取所有数的二进制位
    vector<vector<int> > nums(n);
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        nums[i] = int_to_bit(num);
    }
    
    int res = 0;
    
    // 遍历每一位
    for (int i = 0; i < 32; ++i) {
        int zerocnt = 0;
        int onecnt = 0;
        
        // 统计该位上0和1的数量
        for (auto& num : nums) {
            if (num[i] == 0) {
                zerocnt++;
            } else {
                onecnt++;
            }
        }
        
        // 如果目标位是0
        if (k_bit[i] == 0) {
            // 需要将所有1翻转为0，或者保留0的位，取较小的次数
            res += zerocnt;
        } 
        // 如果目标位是1
        else {
            // 如果所有数的该位都是0，则需要翻转其中一个
            if (zerocnt == n) {
                res += 1;
            }
            // 否则不需要翻转
        }
    }
    
    cout << res << endl;
    
    return 0;
}