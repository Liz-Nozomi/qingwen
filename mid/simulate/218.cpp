#include <bits/stdc++.h>
using namespace std;


string largeadd(string a,string b){
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    int len1 = a.size();
    int len2 = b.size();

    int maxlen = max(len1,len2);
    string res;
    int carry = 0;

    for(int i=0;i<maxlen;i++){
        int digit1=0,digit2=0;
        if(i < len1){
            digit1 = a[i] - '0';

        }
        if(i < len2){
            digit2 = b[i] - '0';
        }

        int sumdig = digit1 + digit2 + carry;
        res.push_back((sumdig % 10) + '0');
        carry = sumdig/10;
    }
    if(carry > 0){
        res.push_back(carry +'0');
    }

    reverse(res.begin(),res.end());
    return res;


}


int main(){
    string a,b;
    cin>>a>>b;
    cout<<largeadd(a,b);


}