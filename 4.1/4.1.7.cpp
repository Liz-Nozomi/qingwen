#include <bits/stdc++.h>
using namespace std;


struct stu{
    string name;
    int score;
    stu(){}
    stu(string _n,int _s){
        name=_n;
        score=_s;
    }
};

bool cmp(stu &a,stu &b){
    if(a.score==b.score)
        {return a.name<b.name;}
        else{return a.score>b.score;}
}

int main(){
    int n;
    cin>>n;
    vector<stu> table;
    for(int i=0;i<n;i++){
        stu temp;
        cin>>temp.name>>temp.score;
        table.push_back(temp);
    }
    sort(table.begin(),table.end(),cmp);
    for(stu line:table){
        cout<<line.name<<" "<<line.score<<endl;
    }
}