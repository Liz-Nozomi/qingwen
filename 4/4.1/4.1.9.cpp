#include <bits/stdc++.h>
using namespace std;


struct stu{
    string name;
    int chinese;
    int math;
    stu(){}
    stu(string _n,int _c,int _m){
        name=_n;
        chinese=_c;
        math=_m;
    }
};

bool cmp1(stu &a,stu &b){
    if(a.chinese==b.chinese)
        {return a.name<b.name;}
        else{return a.chinese>b.chinese;}
}

bool cmp2(stu &a,stu &b){
    if(a.math==b.math)
        {return a.name<b.name;}
        else{return a.math>b.math;}
}

bool cmp3(stu &a,stu &b){
    if(a.math+a.chinese==b.math+b.chinese)
        {return a.name<b.name;}
        else{return a.math+a.chinese>b.math+b.chinese;}
}

int main(){
    int n,k;
    cin>>n>>k;

    vector<stu> table;
    for(int i=0;i<n;i++){
        stu temp;
        cin>>temp.name>>temp.chinese>>temp.math;
        table.push_back(temp);
    }
    if(k==1){
        sort(table.begin(),table.end(),cmp1);}
    else if (k==2){sort(table.begin(),table.end(),cmp2);}
    else {sort(table.begin(),table.end(),cmp3);}

    for(stu line:table){
        cout<<line.name<<" "<<line.chinese<<" "<<line.math<<" "<<line.chinese+line.math<<endl;
    }
}