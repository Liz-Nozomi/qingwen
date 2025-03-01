#include <bits/stdc++.h>
using namespace std;

int main(){
    string n;
    int k;
    cin>>n>>k;
    vector<bool> allow(10,true);
    for(int i=0;i<k;i++){
        int t;
        cin>>t;
        allow[t] = false;
    }


    string res;
    bool bigger = false;
    bool looped = false;
here: 
    for(auto cha:n){
        int digit = cha - '0';
        

        for(int i=0;i<=9;i++){
            if(!bigger){
                if(i == digit and allow[i]){
                    res.push_back(i + '0');
                
                    break;
                }
                else if(i > digit and allow[i]){
                    res.push_back(i + '0');
                    bigger = true;
                    break;
                }
            }else{
                if(allow[i]){
                    res.push_back(i + '0');
                    break;
                }
            }


        }
    }
    
    if((res.size() == 0 or stoi(res) <= stoi(n)) and !looped){
        res.clear();
        for(int i=1;i<10;i++){
            if(allow[i]){
                res.push_back(i + '0');
                break;
            }
        }
        looped = true;
        bigger = true;
        goto here;

    }
    
    cout<<res;

}