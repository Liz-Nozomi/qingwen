#include <bits/stdc++.h>
using namespace std;

struct node{
    int l;
    int r;
    int idx;
    int value;
    int depth;

};
int main(){
    int n;
    cin>>n;
    vector<node> tree(n);
    for(int i=0;i<n;i++){
        cin>>tree[i].value;
        tree[i].idx = i;
    }
    for(int i=0;i<n;i++){
        cin>>tree[i].l>>tree[i].r;
    }

    stack<int> s;
    s.push(0);
    tree[0].depth = 0;
    int res = 0;
    while(!s.empty()){
        int current = s.top();

        s.pop();
        if(tree[current].l == -1 and tree[current].r == -1){
            res += tree[current].depth * tree[current].value;
        }

        
        if(tree[current].r != -1){
            tree[tree[current].r].depth = tree[current].depth +1;
            s.push(tree[current].r); 
        }
        if(tree[current].l != -1){
            tree[tree[current].l].depth = tree[current].depth +1;
            s.push(tree[current].l); 
        }
        
    }
    cout<<res;

}
