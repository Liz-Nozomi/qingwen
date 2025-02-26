#include <bits/stdc++.h>
using namespace std;


string largemult(string a,string b){
    if(a == "0" or b == "0"){
        return "0";
    }


    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    
    int len1 = a.size();
    int len2 = b.size();

    int maxlen = max(len1,len2);
    string res(len1+len2,'0');

    for(int i=0;i<len1;i++){
        for(int j=0;j<len2;j++){
            int digit1 = a[i] - '0';
            int digit2 = b[j] - '0';

            int product = digit1*digit2 + (res[i+j] - '0');
            res[i+j] = (product % 10) + '0';

            int carry = product / 10;
            int carrypos = i+j+1;
            while(carry > 0){
                if(carrypos >= res.size()){
                    res.push_back('0');
                }
                int temp = (res[carrypos] - '0') + carry;
                res[carrypos] = (temp%10) + '0';

                carry = temp / 10;
                carrypos ++;
            }
        }
    }
    while(res.back() == '0'){
        res.pop_back();
    }


    reverse(res.begin(),res.end());
    return res;


}


int main(){
    string a,b;
    cin>>a>>b;
    cout<<largemult(a,b);


}