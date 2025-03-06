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