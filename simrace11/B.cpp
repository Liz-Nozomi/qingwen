#include <bits/stdc++.h>
using namespace std;
class unionfind{
    private:
        vector<int> parent;
        vector<int> rank;
        int n;
    public:
        void init(int size){
            n = size;
            parent.resize(size);
            rank.resize(size,0);

            for(int i=0;i<size;i++){
                parent[i] = i;
            }
        }

        int find(int x){
            if(parent[x] != x){
                parent[x] = find(parent[x]);
                //路径压缩
            }
            return parent[x];
        }

        void unite(int x,int y){
            int rootX = find(x);
            int rootY = find(y);

            if(rootX == rootY){
                return;
            }

            if(rank[rootX] > rank[rootY]){
                parent[rootY] = rootX;
            }
            else if(rank[rootY] > rank[rootX]){
                parent[rootX] = rootY;
            }
            else{
                parent[rootY] = rootX;//default
                rank[rootX] ++;
            }




        }

};

int main(){
    int n,m;
    cin>>n>>m;
    //俺寻思这玩意就是个并查集
    unionfind uf;
    uf.init(n+1);

    for(int i=0;i<m;i++){
        int a,b,r;
        cin>>a>>b>>r;
        uf.unite(a,b);
    }
    set<int> uff;
    for(int i=1;i<=n;i++){
        uff.insert(uf.find(i));
    }
    cout<<uff.size();

}