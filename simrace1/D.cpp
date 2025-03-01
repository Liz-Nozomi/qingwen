#include <bits/stdc++.h>
using namespace std;
struct member{
    int base;
    int level;
    member(){}
};

bool sort1(member a,member b){
    if(a.base == b.base){
        return a.level > b.level;
    }
    else{
        return a.base > b.base;
    }
}

//目标：
int main(){
    int n;
    cin>>n;
    vector<member> a(n);
    vector<member> b(n);

    int basea=0,levela=0,baseb=0,levelb=0;
    for(int i=0;i<n;i++){
        cin>>a[i].base>>a[i].level;
        basea += a[i].base;
        levela += a[i].level;
    }
    for(int i=0;i<n;i++){
        cin>>b[i].base>>b[i].level;
        baseb += b[i].base;
        levelb += b[i].level;
    }
    sort(a.begin(),a.end(),sort1);
    sort(b.begin(),b.end(),sort1);

    int gap[501][501];
    int gap_base = abs(basea - baseb);
    int min_gap_base = gap_base;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            gap[i][j] = min(gap_base, abs (  ( basea - a[i].base + b[j].base ) - (baseb - b[j].base + a[i].base) ));
            if(gap[i][j] < min_gap_base){
                min_gap_base = gap[i][j];
            }

        }
    }
    
    
    int min_gap_level = INT_MAX;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(gap[i][j] == min_gap_base){
                min_gap_level = min(min_gap_level, abs( (levela - a[i].level + b[i].level) - (levelb - b[i].level + a[i].level))) ;
            }
        }
    }

    
    cout<<min_gap_base<<" "<<min_gap_level;

}