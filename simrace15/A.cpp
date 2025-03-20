#include <bits/stdc++.h>
using namespace std;

int main(){
#define int long long
    int w,h;
    cin>>w>>h;//x>=0 x<=w;y>=0,y<=h
    int n;
    cin>>n;

    int xmin = 0;
    int xmax = w;
    int ymin = 0;
    int ymax = h;

    for(int i=0;i<n;i++){
        int xi,yi,a;
        cin>>xi>>yi>>a;
        if(a == 1){
            xmin = max(xmin,xi);        
        }
        if(a == 2){
            xmax = min(xmax,xi);
        }
        if(a == 3){
            ymin = max(ymin,yi);
        }
        if(a==4){
            ymax = min(ymax,yi);
        }
    }
    if(xmax < xmin or ymax < ymin){
        cout<<0;
    }

    else{
        cout<<(xmax - xmin) * (ymax - ymin);}
}