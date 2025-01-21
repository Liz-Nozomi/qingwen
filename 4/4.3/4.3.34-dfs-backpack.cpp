#include <bits/stdc++.h>
using namespace std;


vector<int> wi;
vector<int> ci;
int n,w;
int maxVal=0;

void DFS(int index,int sumW,int sumC){
    if(index==n){
        if(sumW<=w and sumC>maxVal){
            maxVal=sumC;
        }
        return;
    }

    DFS(index+1,sumW,sumC);//不选i
    DFS(index+1,sumW+wi[index],sumC+ci[index]);//选i


}

int main(){
    
    cin>>n>>w;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        wi.push_back(temp);
    }
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        ci.push_back(temp);
    }      
    DFS(0,0,0);
    cout<<maxVal;
}