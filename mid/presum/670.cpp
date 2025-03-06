#include <bits/stdc++.h>
using namespace std;

#define int long long
int in()
{
    int k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        k = k * 10 + (c - '0');
        c = getchar();
    }
    return k * f;
}

int main()
{
    int n, k;
    n = in();
    k = in();

    if (k == 0)
    {
        // Handle the case where k is zero (though problem constraints may prevent this)
        cout << 0 << endl;
        return 0;
    }

    vector<int> mod_count(k, 0);
    mod_count[0] = 1; // Initial state for prefix sum 0
    int current_sum = 0;
    int cnt = 0;

    for (int i = 0; i < n; ++i)
    {
        int num = in();
        current_sum += num;
        int current_mod = (current_sum % k + k) % k; // Ensure non-negative
        cnt += mod_count[current_mod]; // Add the count of previous occurrences
        mod_count[current_mod]++; // Update the current remainder's count
    }

    cout << cnt << endl;
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
#define int long long
int in()
{
    int k=0,f=1;//f 符号
    char c=getchar();
    while(c<'0'||c>'9')//非数字扔了
    {
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        k=k*10 + (c-'0');
        c=getchar();
    }
    return k*f; // 别忘记标记的负数要乘进去
}
#undef int
int main(){
#define int long long
int n,k;
n=in();k=in();

vector<int> nums(n);
vector<int> presum(n,0);//到i为止的所有数的和

for(int i=0;i<n;i++){
    nums[i] = in();
    if(i > 0){
        presum[i] = nums[i] + presum[i-1];
    }else{
        presum[i] = nums[i];
    }
}
int cnt = 0;
for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
        if((presum[j] - presum[i] + nums[i]) % k == 0){
            cnt++;
        }
    }
}
cout<<cnt;
}
*/