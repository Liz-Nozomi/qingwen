#include <bits/stdc++.h>
using namespace std;
struct Linknode{
    
    int data;
    int next;
    int prev;

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
    int idprev;
    int sttrev;
    while(i != -1){
        if(v[i].next ==-1){
            sttrev = i;
        }
        if(i == stt){
            v[i].prev = -1;
        }else{
            v[i].prev = idprev;
        }
        idprev = i;
        i=v[i].next;
    }

    int fr = stt;
    int re = sttrev;
    vector<int> f;
    vector<int> r;
    while(fr != -1){
        
        f.push_back(v[fr].data);
        fr=v[fr].next;
    }
    while(re != -1){
        
        r.push_back(v[re].data);
        re=v[re].prev;
    }
    cout<<(f == r?"Yes":"No");

}