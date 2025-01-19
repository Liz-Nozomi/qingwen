#include <bits/stdc++.h>
using namespace std;
vector<int> nums;
int idx;

void binsearch(int n, int find) {
    int left = 0, right = n - 1;
    idx = -1;  // 初始化为n，表示未找到

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == find) {
            idx = mid;  // 更新最小索引
            right = mid - 1;  // 继续在左半部分查找
        } else if(nums[mid] > find){
            right = mid-1;
        }
        else {
            left = mid + 1;  // 在右半部分查找
        }
    }
}

int main(){
    int n,x;

    cin>>n>>x;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }

    
    binsearch(n,x);
    cout<<idx;

}