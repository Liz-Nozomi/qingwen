#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> wi;
    int n,W,sum=0,cnt=0;
    cin>>n>>W;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        wi.push_back(temp);
    }
    sort(wi.begin(),wi.end());
    for(auto it:wi){
        if(sum+it <= W){
            cnt++;
            sum+=it;
        }
        else{
            break;
        }
    }
    cout<<cnt<<" "<<sum;

}