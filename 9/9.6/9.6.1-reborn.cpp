#include <bits/stdc++.h>
using namespace std;

int findFather(int n,vector<int> &father){
    int temp = n;
    while(father[temp] != -1){
        temp = father[temp];
    }
    int root = temp;

    while(father[n] != -1){
        int fatherN = father[n];
        father[n] = root;
        n = fatherN;
    }
    return root;

}



//function to merge sets
void unionSet(int a,int b, vector<int>&father){
    int faA = findFather(a,father);
    int faB = findFather(b,father);
    if(faA != faB){
        father[faB] = faA;
    }
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<int> father(n,-1);
    //Initialize


    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        //merge sets
        unionSet(a-1,b-1,father);

    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(father[i] == -1){
            cnt++;
        }
    }

    cout<<cnt;
    


}