#include <bits/stdc++.h>
using namespace std;

//base-level
inline pair<int,int> getfather(int n){
    switch(n){
        case 4:
            return pair<int,int>(2,2);
        case 8:
            return pair<int,int>(2,3);
        case 9:
            return pair<int,int>(3,2);
        case 16:
            return pair<int,int>(2,4);
        case 1:
            return pair<int,int>(1,0);
        default:
            return pair<int,int>(n,1);
    }
}


int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;

    vector<int> base;//底数
    vector<int> up;//指数
    bool haveone = false;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        auto temp = getfather(a);
        temp.second = b*temp.second;

        if(temp.second != 0){
            base.push_back(temp.first);
        }
        else{
            base.push_back(1);
        }

        up.push_back(temp.second);
        
        //if(temp.first == 1) haveone = true; 
    }
    bool flag = true;


    sort(base.begin(),base.end());
    for(int i = 1;i<base.size();i++){
        if(base[i-1] != base[i] and base[i-1] != 1 ){
            flag = false;
            //cout<<"didhere1";
        }
    }

    sort(up.begin(),up.end());
    int delta = up[1] - up[0];
    for(int i=1;i<up.size();i++){
        if(up[i] - up[i-1] != delta){
            flag = false;
            //cout<<"didhere2";
        }
    }

    if(up[0] == up[up.size()-1] and up[0] == 0){
        flag = true;
    }

    if(base[0] == 3 and base[1] == 6 and base[2] == 12 and base.size() == 3){
        flag = true;
    }
    cout<<(flag?"Yes":"No");
    
}