#include <bits/stdc++.h>
using namespace std;
class BIT{
    private:
        int n;
        vector<int> tree;
    public:
        int lowbit(int num){
            return num & (-num);
        }
        BIT(int size){
            n=size;
            tree.resize(n+1,0);
        }//构造函数
        void update(int idx,int value){
            while(idx <= n){
                tree[idx] += value;
                idx += lowbit(idx);
            }

        }//将idx的值增加value

        int query(int idx){//1 到 idx的区间和
            int sum = 0;
            while(idx > 0){
                sum += tree[idx];
                idx -= lowbit(idx);
            }
            return sum;
        }

        int get(int idx){
            return query(idx) - query(idx-1);
        }//单点查询

        void set(int idx,int value){
            update(idx,value - get(idx));
        }//单点设置值

};

int main(){
    int n,m;
    cin>>n>>m;
    BIT bit(n);

    for(int i=0;i<m;i++){
        string op;
        cin>>op;
        if(op == "Add"){
            int a,b;
            cin>>a>>b;
            bit.update(a,b);
        }else if(op == "Query"){
            int q;
            cin>>q;
            cout<<bit.query(q)<<endl;
        }
    }
}