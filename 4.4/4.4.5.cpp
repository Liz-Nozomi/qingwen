#include <bits/stdc++.h>
using namespace std;

struct interval{
    int start;
    int end;
    int length;
    interval(int _start,int _end){
        start=_start;
        end=_end;
        length=end-start;    
    }
};

bool cmp(interval i1,interval i2){
    if(i1.start != i2.start){
        return i1.start>i2.start;
    }
    else return i1.end < i2.end;
}

int main(){
    int n;
    cin>>n;
    vector<interval> intervals;
    for(int i=0;i<n;i++){
        int temp1,temp2;
        cin>>temp1>>temp2;
        intervals.push_back(interval(temp1,temp2));

    }
    sort(intervals.begin(),intervals.end(),cmp);
    int ints=1,currentend=intervals[0].start;
    
    for(int i=1;i<n;i++){
        if(intervals[i].end <= currentend){
            ints++;
            currentend = intervals[i].start;
            //cout<<currentend<<endl;
        }
    }
    cout<<ints;

    



}