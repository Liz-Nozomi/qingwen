#include <iostream>
using namespace std;
int main() {
    int n ,u,d;
    scanf("%d %d %d", &n,&u,&d);
    int dist=0,count=0;
    while(dist<=n){
        dist+=u;
        count++;
        if(dist>=n){
            break;
        }
        dist-=d;

    }
    cout<<count<<endl;
} 