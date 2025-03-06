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

        int get(int idx) {
            if (idx == 0) return 0;  // 防止 idx = 0 时的错误
            return query(idx) - query(idx - 1);
        }//单点查询

        void set(int idx,int value){
            update(idx,value - get(idx));
        }//单点设置值

};//下标从1开始

int main(){
    int n;
    cin>>n;
    vector<int> a;

    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        a.push_back(tmp);
    }

    auto b = a;
    cout<<"here";
    sort(a.begin(),a.end());

    BIT bit(n);
    
    map<int,int> mp;
    mp[a[0]] = 0;
    
    for(int i=1;i<n;i++){
        if(a[i] != a[i-1]){
            mp[a[i]] = mp[a[i-1]] +1;
        }

    }
    vector<int> res;
    for(int i=0;i<n;i++){
        res.push_back(mp[b[i]-1]);
        bit.update(mp[b[i]],1);
    }
    cout<<res.size();

}