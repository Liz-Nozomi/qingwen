#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    vector<int> nums,prezero,preone,pretwo;
    int n;
    cin>>n;
    int temp;
    cin>>temp;
    nums.push_back(temp);
    if(temp == 0){
        prezero.push_back(1);
        preone.push_back(0);
        pretwo.push_back(0);
    }
    else if(temp == 1){
        prezero.push_back(0);
        preone.push_back(1);
        pretwo.push_back(0);
    }
    else if(temp == 2){
        prezero.push_back(0);
        preone.push_back(0);
        pretwo.push_back(1);
    }




    for(int i=1;i<n;i++){
        int temp;
        cin>>temp;
        nums.push_back(temp);

        if(temp == 0){
        prezero.push_back(prezero[i-1]+1);
        preone.push_back(preone[i-1]);
        pretwo.push_back(pretwo[i-1]);

        
    }
        else if(temp == 1){
        prezero.push_back(prezero[i-1]);
        preone.push_back(preone[i-1]+1);
        pretwo.push_back(pretwo[i-1]);
    }
        else if(temp == 2){
        prezero.push_back(prezero[i-1]);
        preone.push_back(preone[i-1]);
        pretwo.push_back(pretwo[i-1]+1);
    }
    }
    ll acc=0;
    for(int i=0;i<n;i++){
        if(nums[i] == 1){
            acc += (prezero[i]) * (pretwo[n-1]-pretwo[i]);
        }
    }
    cout<<acc;

    

}

