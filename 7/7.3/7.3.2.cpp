#include <bits/stdc++.h>
using namespace std;
struct Linknode{
    
    int data;
    int next;
};

int main(){
    
    int n,stt;
    cin>>n>>stt;
    vector<Linknode> v(n+1);
    for(int i=0;i<n;i++){
        Linknode temp;
        int id;
        cin>>id>>temp.data>>temp.next;
        v[id].data =temp.data;
        v[id].next = temp.next; 
    }
    int i=stt;
    int cnt=0;
    while(i != -1){
        i=v[i].next;
        cnt++;
    }
    cout<<cnt;
}