#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> target;
    stack<int> ref;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        
        target.push_back(temp);
    }
    int idx=0;
    for(int i=0;i<n;i++){
        ref.push(i+1);
        while(!ref.empty() and ref.top() == target[idx] and idx < target.size() ){
            //cout<<ref.top()<<endl;

            ref.pop();
            idx++;
        }

    }
    if(ref.empty()){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    


}