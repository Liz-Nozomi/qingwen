#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    long long res = a + b;
    string res_t = to_string(res);
    //cout<<res_t;

    string res_o;
    int cnt = 0;
if(res > 0){
    reverse(res_t.begin(),res_t.end());

    for(auto it:res_t){

        cnt++;
        res_o.push_back(it);
        

        if(cnt % 3 == 0 and cnt < res_t.size()){
            res_o.push_back(',');
        }

    }
    reverse(res_o.begin(),res_o.end());
    cout<<res_o;
}
else if(res < 0){
    for(auto it:res_t){
        if(it == '-'){
            res_o.push_back('-');

        }else{
            cnt++;
            res_o.push_back(it);
        }

        if(cnt % 3 == 0 and cnt != 0 and cnt < res_t.size()-1){
            res_o.push_back(',');
        }

    }
    cout<<res_o;
}
}