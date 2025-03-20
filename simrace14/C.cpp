#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    unsigned long k;
    cin>>s>>k;

    //对于每个数，找到右边第j(min(kremain,length))个最大的数，并且顶上来
    for(unsigned long i=0;i<s.length();i++){
        int maxmov = min(k,s.length() - i-1);


        int nxtmax = s[i] - '0';
        int nxtloc = i;
        for(unsigned long j=i;j<=i+maxmov;j++){
            if(s[j]- '0' > nxtmax ){
                nxtmax = s[j]-'0';
                nxtloc = j;
            }
        }
        //cout<<i<<" "<<maxmov<<" "<<nxtmax<<" "<<nxtloc<<" "<<k<<endl;
        //找到可以移动的最近量
        if(nxtmax != s[i]-'0'){//最起码得动
            s.erase(s.begin() + nxtloc);
            s.insert(s.begin() + i,nxtmax + '0');
            k -= (nxtloc - i);
        }
        //cout<<s<<endl;
    }
    if(k > 0){
        for(int i=0;i<k;i++){
            int sz = s.size();
            swap(s[sz-1],s[sz-2]);
        }
    }
    cout<<s<<endl;
    


}