#include <bits/stdc++.h>
using namespace std;
vector<int> sticks;
const int MAXN = 1000;          // 最多有1000根木棍
const int MAXK = 100000000;  
int binarySearch(int n,int k) {
    int l = 0, r = MAXK;  // 初始化二分查找的左右边界，左边界为0，右边界为最大可能长度
    while (l < r) {       // 当左边界小于右边界时，继续二分查找
        int mid = (l + r + 1) / 2;  // 计算中间值，+1是为了避免死循环
        int stickCount = 0;         // 用于统计当前中间值下可以切割出的段数

        // 遍历所有木棍，计算每根木棍可以切割出的段数
        for (int i = 0; i < n; i++) {
            stickCount += sticks[i] / mid;  // 每根木棍可以切割出的段数为长度除以mid
        }

        // 如果当前段数小于k，说明mid太大，需要减小
        if (stickCount < k) {
            r = mid - 1;  // 将右边界调整为mid-1
        } else {
            l = mid;  // 否则，将左边界调整为mid
        }
    }
    return l;  // 返回最终的最大段长度
}


int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        sticks.push_back(temp);
    }
    cout<<binarySearch(n,k);

}