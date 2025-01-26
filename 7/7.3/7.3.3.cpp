#include <bits/stdc++.h>
using namespace std;
struct Linknode{
    
    int data;
    int next;
};

int main(){
    
    int n,stt;
    cin>>n>>stt;
    vector<Linknode> v(1000);
    for(int i=0;i<n;i++){
        Linknode temp;
        int id;
        cin>>id>>temp.data>>temp.next;
        v[id].data =temp.data;
        v[id].next = temp.next; 
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        Linknode temp;
        int idx;
        cin>>idx>>temp.data;
        
        v[idx].data = temp.data;
        v[idx].next = stt;
        stt = idx;
    }

    int i=stt;
    while(i != -1){
        cout<<i<<" "<<v[i].data<<" "<<v[i].next<<endl;
        i=v[i].next;
    }

}