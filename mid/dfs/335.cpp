#include <bits/stdc++.h>
using namespace std;
struct node{
    int l;
    int r;
    int idx;
};
int main(){
    int n;
    cin>>n;
    vector<node> tree(n);
    for(int i=0;i<n;i++){
        cin>>tree[i].l>>tree[i].r;
        tree[i].idx = i;
    }

    stack<int> s;
    s.push(0);

    while(!s.empty()){

        auto temp = s.top();
        s.pop();

        swap(tree[temp].l,tree[temp].r);

        if(tree[temp].l != -1){
            s.push(tree[temp].l);
        }
        if(tree[temp].r != -1){
            s.push(tree[temp].r);
        }
    }


    vector<int> inorder;
    stack<int> stack_in;
    int current = 0;

    while (current != -1 || !stack_in.empty()) {
        // 向左子树深入，并将沿途节点压入栈
        while (current != -1) {
            stack_in.push(current);
            current = tree[current].l;
        }

        // 弹出栈顶节点并访问
        current = stack_in.top();
        stack_in.pop();
        inorder.push_back(current);

        // 转向右子树
        current = tree[current].r;
    }



    vector<int> preorder;
    stack<int> stack_pre;
    stack_pre.push(0);
    while(!stack_pre.empty()){
        int current = stack_pre.top();
        stack_pre.pop();
        preorder.push_back(current);

        if(tree[current].r != -1){
            stack_pre.push(tree[current].r);
        }
        if(tree[current].l != -1){
            stack_pre.push(tree[current].l);
        }


    }

    int temp = 0;
    for(auto it:preorder){
        cout<<it;
        temp++;
        if(temp < preorder.size()){
            cout<<" ";
        }
    }
    cout<<endl;
    temp = 0;
    for(auto it:inorder){
        cout<<it;
        temp++;
        if(temp < inorder.size()){
            cout<<" ";
        }
    }

}