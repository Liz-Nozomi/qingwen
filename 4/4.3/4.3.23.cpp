#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;
int n;

vector< vector<int> >res;
vector<int> templ;
bool used[10]={false};

void DFS(int currentPos){
    if(currentPos==n+1){
        res.push_back(templ);   
        return;
    }
    for(int i=1;i<=n;i++){
        if(!used[i]){
    
            templ.push_back(i);
            used[i]=true;
            DFS(currentPos+1);
            used[i]=false;
            templ.pop_back();
        }
    }
}





int main(){
    cin>>n;

    DFS(1);


    for(auto it:res){
        int t=0;
        for(auto it2:it){

            cout<<it2;
            t++;
            if(t<it.size()){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    

}