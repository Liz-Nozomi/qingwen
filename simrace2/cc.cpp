#include <bits/stdc++.h>
using namespace std;
int to_num(string date){
    int yyyy = stoi(date.substr(0,4));
    int mm = stoi(date.substr(5,2));
    int dd = stoi(date.substr(8,2));

    return dd + mm * 100 + yyyy * 10000;
}
int main(){
    int n;
    cin>>n;
    int currentdate = 20240906;
    int youngest = 0,oldest = INT_MAX;
    string youngestname,oldestname;
    int validcnt = 0;


    for(int i=0;i<n;i++){
        string name;
        string date;
        cin>>name>>date;
        int datenum = to_num(date);
        if(currentdate-datenum <= 2000000 and currentdate >= datenum){
            validcnt++;
            if(datenum < oldest){
                oldestname = name;
            }
            if(datenum > youngest){
                youngestname = name;
            }
        }    
    }

    cout<<validcnt<<" "<<oldestname<<" "<<youngestname;
}