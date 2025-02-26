#include <bits/stdc++.h>
using namespace std;
vector<int> res;
int range[10000];

int findm3(int n){//找到最高数位
    

    int maxpos = 0;//值域最大值
    int maxneg = 0;//值域最小值

    int maxposi = 0;
    int maxnegi = 1;
    

    if(n == 0){
        return 0;
    }
    else if(n > 0){
        while(2 * (maxpos + pow(3,maxposi)) < n){
            maxpos = maxpos + pow(3,maxposi);
            range[maxposi] = maxpos * 2;
            maxposi=maxposi+2;
            

        }
        range[maxposi] = 2*(maxpos + pow(3,maxposi));
        return maxposi;
        
    }
    else{
        while(2 * (maxneg + pow(-3,maxnegi)) > n){
            maxneg = maxneg + pow(-3,maxnegi);
            range[maxnegi] = maxneg * 2;
            maxnegi = maxnegi + 2;

        }
        range[maxnegi] = 2*(maxneg + pow(-3,maxnegi));

        return maxnegi;
    }

}

void finddig(int n,int i){
    int dig = 0;

    if(n == 0 or i < 0){
        return;
    }
    if(i == 0){
        if(n == 1){
            res.push_back(1);
        }
        if(n == 2){
            res.push_back(2);
        }
        return;
    }

    if(i % 2 == 1){
        if( (n - pow(-3,i)) <= range[i-1] ){
            dig = 1;
        }
        if( (n - 2 * pow(-3,i)) <= range[i-1]){
            dig = 2;
        }
    }
    
    if(i % 2 == 0){
        if(n - pow(-3,i) >= range[i-1]){
            dig = 1;
        }
        if(n - 2*pow(-3,i) >= range[i-1]){
            dig = 2;
        }
    }

    res.push_back(dig);
    //cout<<"called"<<i<<" "<<dig<<endl;
    finddig(n - dig * pow(-3,i) , i-1);
    

}


int main(){
    int n;
    cin>>n;
    int topi = findm3(n);//最高数位
    findm3(-n);

    finddig(n,topi);
    for(int i=0;i<res.size();i++){
        cout<<res[i];
    }
    for(int i=res.size();i<=topi;i++){
        cout<<0;
    }

}