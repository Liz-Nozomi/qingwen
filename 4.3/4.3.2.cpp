#include <bits/stdc++.h>
using namespace std;
string A(int t){
    if(t==0){
        return"讲你妹的故事啊！快点去睡觉！！！";
    }else{
        return(
        "从前有座山，山上有座庙\n庙里有一个老和尚和一个小和尚\n睡前老和尚给小和尚讲故事：\n"+A(t-1)+"\n然后老和尚和小和尚就睡觉啦");

    }
}
int main(){
    int n;
    cin>>n;
    string s=A(n);
    cout<<s;
    
}