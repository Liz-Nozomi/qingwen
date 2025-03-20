#include <bits/stdc++.h>
using namespace std;

struct book{
    int x;
    int y;
};

bool cmp(book x,book y){
    if(x.x != y.x){
        x.x > y.x;
    }else{
        return x.y > y.y;
    }
}
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<book> books(n);
    for(int i=0;i<n;i++){
        cin>>books[i].x>>books[i].y;
    }

    sort(books.begin(),books.end(),cmp);
    int totala =0;
    int totalb =0;
    int tb = 0;
    for(int i=1;i<=n;i++){
        totala += books[i-1].x;
        totalb += books[i-1].y;
        if(totala >= a and totalb >=b){
            tb = i;
            break;
        }
    }
    cout<<tb;
}