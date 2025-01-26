#include <bits/stdc++.h>
using namespace std;
struct Linknode{
    
    int data;
    int next;
};
int stt;
void deletenode(vector<Linknode> &v,int id,int idprev){
    if(id == stt){
        stt = v[id].next;
    }
    else{
        v[idprev].next = v[id].next;
    }
}

int main(){
    
    int n,k;
    cin>>n>>stt>>k;
    vector<Linknode> v(1000);
    for(int i=0;i<n;i++){
        Linknode temp;
        int id;
        cin>>id>>temp.data>>temp.next;
        v[id].data =temp.data;
        v[id].next = temp.next; 
    }


    int i=stt;
    int idprev = stt;
    while(i != -1){
        int flag = 0;
        if(v[i].data == k){
            deletenode(v,i,idprev);
            flag = 1;
        }
        if(flag == 0){
            idprev = i;
        }
        i = v[i].next;
    }

    i = stt;
    while(i != -1){
        cout<<i<<" "<<v[i].data<<" "<<v[i].next<<endl;
        i=v[i].next;
    }
}