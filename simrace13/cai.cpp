#include <bits/stdc++.h>
using namespace std;
int findpairlocation(vector< string > &groups,string name){
    for(int i=0;i<groups.size();i++){
        if(groups[i] == name){
            return i;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    vector< string > groups(n*2);
    map<string,string> pairs;

    for(int i=0;i<n;i++){
        string s1,s2;
        cin>>s1>>s2;
        groups[2*i] = s1;
        groups[2*i+1] = s2;
        pairs[s1] = s2;
        pairs[s2] = s1;
    }

    int cs = 0;
    vector<string> res;


    for(int i=0;i<q;i++){
        char cmd;
        cin>>cmd;
        if(cmd == 'G'){
            if(cs == 0){
                cs++;
            }else{
                cs--;
            }
        }

        if(cmd == 'H'){
            if(cs == 2*n-1){
                cs--;
            }else{
                cs++;
            }
        }

        if(cmd =='I'){
            int temp = cs;
            string tname = groups[temp];
            if(cs == 2*n-1){
                cs = 0;
            }else{
                //cs应该不变
            }//saki，移动
            groups.erase(groups.begin() + temp);
            groups.push_back(tname);
        }

        if(cmd == 'J'){
            int temp = cs;
            string tname = groups[temp];
            if(cs == 2*n-1){
                cs = 0;
                int insloc = findpairlocation(groups,tname);
                groups.erase(groups.begin() + temp);
                groups.insert(groups.begin() + insloc + 1,tname);
             
            }else{
                cs++;
                int insloc = findpairlocation(groups,tname);
                if(insloc < cs){
                    groups.erase(groups.begin() + temp);
                    groups.insert(groups.begin() + insloc + 1,tname);
                }
                else{
                    cs--;
                    groups.erase(groups.begin() + temp);
                    groups.insert(groups.begin() + insloc + 1,tname);
                 
                }
            }//saki，移动

              //very very slow
        }

        if(cmd == 'K'){
            res.push_back(groups[cs]);
        }
    }
    
    for (const auto& s : res) { cout << s << endl; } for(auto it:groups){ cout<<it<<endl; } return 0;


}