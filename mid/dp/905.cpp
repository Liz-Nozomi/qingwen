#include <bits/stdc++.h>
using namespace std;


int main(){
    #define int long long
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    vector<char> s(n+1);

    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    
    int dp_a[100010];
    int dp_b[100010];
    int dp_c[100010];
    int cnt[100010];

    dp_a[0] = 0;
    dp_b[0] = 0;
    dp_c[0] = 0;
    cnt[0] = 1;

    for(int i=1;i<=n;i++){
        if(s[i] == 'X'){
            dp_a[i] = dp_a[i-1] + cnt[i-1];
            dp_b[i] = dp_b[i-1];
            dp_c[i] = dp_c[i-1];
            cnt[i] = cnt[i-1];

        }
        if(s[i] == 'Y'){
            dp_a[i] = dp_a[i-1];
            dp_b[i] = dp_b[i-1] + dp_a[i-1];
            dp_c[i] = dp_c[i-1];
            cnt[i] = cnt[i-1];

        }
        if(s[i] == 'Z'){
            dp_a[i] = dp_a[i-1];
            dp_b[i] = dp_b[i-1];
            dp_c[i] = dp_c[i-1]+dp_b[i-1];
            cnt[i] = cnt[i-1];

        }
        if(s[i] == '?'){
            dp_a[i] = (dp_a[i-1] * 3 + cnt[i-1]) % 1000000007;
            dp_b[i] = (dp_b[i-1] * 3 + dp_a[i-1]) % 1000000007;
            dp_c[i] = (dp_c[i-1] * 3 + dp_b[i-1]) % 1000000007;
            cnt[i] = (cnt[i-1] * 3) % 1000000007;

        }
    }

    cout<<dp_c[n] % 1000000007;

}