#include <bits/stdc++.h>
using namespace std;
int BFS(int s,int n){
    queue<pair<int,int> > q;
    bool used[100000];
    
    q.push(pair<int,int>(s,0));
    used[s] = true;

    
    while(!q.empty()){
        
        auto tmp = q.front();

        if(tmp.first == n) return tmp.second;
        
        q.pop();


        if(tmp.first*2 <=n and !used[tmp.first * 2]){
            q.push(pair<int,int>(tmp.first * 2,tmp.second+1));
            used[tmp.first * 2]=true;
        }
        if(tmp.first < n and !used[tmp.first + 1]){
            q.push(pair<int,int>(tmp.first + 1,tmp.second+1));
            used[tmp.first+1] = true;
        }
        

    }
    //return cnt;


}

int main(){
    int n;
    cin>>n;
    cout<<BFS(1,n);
}