#include <bits/stdc++.h>
using namespace std;
int mp[8][8];
vector< pair<int,int> > queen;
int direx[8]={0,0,1,1,1,-1,-1,-1};
int direy[8]={-1,1,0,1,-1,0,1,-1};

int DFS(int x,int y,int dirx,int diry){
    x += dirx;
    y += diry;  // 跳过起始位置
    while (x >= 0 && x < 8 && y >= 0 && y < 8) {
        if (mp[x][y] == 1) {  // 遇到其他皇后
            return 1;
        }
        x += dirx;
        y += diry;
    }
    return 0;
}

int main(){
    //input
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin>>mp[i][j];
            if(mp[i][j]==1){
                queen.push_back(pair<int,int>(i,j));
            }
        }
    }
    int tmp=0;
    for(auto it:queen){
        for(int i=0;i<8;i++){
            tmp+=DFS(it.first,it.second,direx[i],direy[i]);
        }
    }
    if(tmp==0){
        cout<<"YES";
    }else cout<<"NO";

}