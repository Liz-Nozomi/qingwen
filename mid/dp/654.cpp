#include<bits/stdc++.h>
using namespace std;

/*
int getLIS(vector<int> &a,int n){
    //It is a dp function
    //time complexity O(n^2) too slow
    if(n == 0)return 0;
    vector<int> dp(n+1,1);
    int LIS = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[j] <= a[i]){
                dp[i] = max(dp[j] +1,dp[i]);
            }
                            
        }
        LIS = max(LIS,dp[i]);
    }
    return LIS;
}
*/


int getLIS(vector<int> a,int n) {
    vector<int> smallest;
    for (int i = 0; i < n; i++) {
        int upper = upper_bound(smallest.begin(), smallest.end(), a[i]) - smallest.begin();
        if (upper == smallest.size()) {
            smallest.push_back(a[i]);
        } else {
            smallest[upper] = a[i];
        }
    }
    return smallest.size();
}

int maxLIS = 0;
void DFS(vector<int> &a,int idx,int n) {
    if (idx == n) {
        maxLIS = max(maxLIS, getLIS(a,n));
        return;
    }
    if (a[idx] == -1) {
        for (int i = 0; i <= 9; i++) {
            a[idx] = i;
            DFS(a,idx + 1,n);
        }
        a[idx] = -1;
    } else {
        DFS(a,idx + 1,n);
    }
}

int main(){
    
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    DFS(a,0,n);
    cout<<maxLIS;


}