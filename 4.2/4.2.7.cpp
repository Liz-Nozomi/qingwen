//#include <bits/stdc++.h>
//using namespace std;
/*
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> target;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        target.push_back(temp);

    }

    int res=0;

    for(int i=0;i<n;i++){
        if(find(target.begin()+i+1,target.end(),k-target[i])!=target.end()){
            res++;
        }
    }


    cout<<res;
}

#include <cstdio>

const int MAXN = 100000;
const int MAXK = 1000001;
int a[MAXN], hashTable[MAXK] = {false};

int main () {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        hashTable[a[i]] = true;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (k - a[i] >= 0 && hashTable[k - a[i]]) {
            ans++;
        }
    }
    printf("%d", ans / 2);
    return 0;
}
*/ 
//俺寻思俺能用map再写一遍

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> target;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        target.push_back(temp);
    }

    map<int,int> inter;

    for(int it:target){
        inter[it]=1;
    }
    int count=0;
    for(int it2:target){
        if(inter[k-it2]==1){
            count++;
        }
    }
    cout<<count/2<<endl;


}
