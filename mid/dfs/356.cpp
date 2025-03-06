#include <bits/stdc++.h>
using namespace std;
struct node{
    int l;
    int r;
    int data = -1;
};
vector<int> res;
void midq(vector<node> &tree,int index){
    if(index == -1){
        return;
    }
    midq(tree,tree[index].l);
    res.push_back(index);
    midq(tree,tree[index].r);
}


vector<int> res2;
void preq(vector<node> &tree,int index){
    if(index == -1){
        return;
    }
    res2.push_back(tree[index].data);
    preq(tree,tree[index].l);
    preq(tree,tree[index].r);
}

int main(){
    int n;
    cin>>n;
    vector<node> tree(n);
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];    
    }

    for(int i=0;i<n;i++){
        node e;
        cin>>e.l>>e.r;
        tree[i] = e;
    }
    midq(tree,0);
    
    int idx = 0;
    sort(nums.begin(),nums.end());
    
    for(auto it:res){
        tree[it].data = nums[idx];
        idx++;
    }
    //cout<<tree[2].data;
    preq(tree,0);

    int cnt = 0;
    for(auto it:res2){
        cout<<it;
        cnt++;
        if(cnt < res2.size()){
            cout<<" ";
        }
    }


}