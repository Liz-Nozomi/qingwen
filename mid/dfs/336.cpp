#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> father;


vector<int> l;
vector<int> r;
vector<int> res;

void findfather(vector<int> BLR,vector<int> LBR,int fa){
    int root = BLR[0];
    int i = 0;
    while(LBR[i] != root){
        i++;
    } 
    father[root] = fa;

    vector<int> LBRleft(LBR.begin(),LBR.begin() + i);
    vector<int> LBRright(LBR.begin()+i+1,LBR.end());


    vector<int> BLRleft(BLR.begin()+1,BLR.begin()+1+i);
    vector<int> BLRright(BLR.begin()+i+1,BLR.end());


    if(BLRleft.size() != 0){
        l[root] = BLRleft[0];
        findfather(BLRleft,LBRleft,root);
    }
    if(BLRright.size() != 0){
        r[root] = BLRright[0];
        findfather(BLRright,LBRright,root);
    }



}

void dfs_LRB(int node){
    if(node == -1){
        return;
    }
    //cout<<"called"<<node<<endl;
    dfs_LRB(l[node]);
    dfs_LRB(r[node]);
    res.push_back(node);
    
}


int main(){
    
    cin>>n;
    vector<int> BLR;
    vector<int> LBR;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        BLR.push_back(temp);
    }

    int rt = BLR[0];

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        LBR.push_back(temp);
    }

    father.resize(n,-1);
    l.resize(n,-1);
    r.resize(n,-1);

    findfather(BLR,LBR,-1);
    //cout<<father[0]<<l[0]<<r[0];
    dfs_LRB(rt);

    int temp = 0;
    for(auto it:res){
        cout<<it;
        temp++;
        if(temp < res.size()){
            cout<<" ";
        }
    }







}