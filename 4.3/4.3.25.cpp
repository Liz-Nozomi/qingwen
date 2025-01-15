#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;
int n;

vector< vector<int> >res;
vector<int> templ,words;
bool used[10]={false};


void DFS(int currentPos){
    if(currentPos==n){
        res.push_back(templ);   
        return;
    }
    for(int i=0;i<n;i++){
        if(!used[i]){
    
            templ.push_back(words[i]);
            used[i]=true;
            DFS(currentPos+1);
            used[i]=false;
            templ.pop_back();
        }
    }
}





int main(){
    cin>>n;

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        words.push_back(temp);
    }
    DFS(0);


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