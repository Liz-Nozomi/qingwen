#include <bits/stdc++.h>
using namespace std;

int reverseNum(int n){
    string s = to_string(n);
    reverse(s.begin(),s.end());
    return stoi(s);
}

int main(){
    int x,y;
    cin>>x>>y;

    queue<int> q;

    q.push(x);

    unordered_map<int,int> visited;
    visited[x] = 1;
    int flag = -1;
    int layer = 0;


    while(!q.empty() and flag == -1){
        int sz = q.size();
        layer++;
        if(layer > 10000){
            break;
        }
        for(int j=0;j<sz;j++){
            auto topp = q.front();
            q.pop();
            if(topp == y){
                flag = layer;
                break;
            }

            if(topp != 0 and visited[topp-1] == 0){
                q.push(topp-1);
                visited[topp-1] = 1;
                
            }
            if(topp % 10 != 0 and visited[reverseNum(topp)] == 0){
                q.push(reverseNum(topp));
                visited[reverseNum(topp)] = 1;
            }
        }
        
    }
    if(flag == -1){
        cout<<"Impossible";
    }else{
        cout<<flag - 1;
    }

}