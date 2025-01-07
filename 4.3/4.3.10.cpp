#include <bits/stdc++.h>
using namespace std;
/*
有一个方法，可以从柱1把1，2，...,n移动到柱3
先把123...n-1移动到柱2，再把n移动到柱3，
再把1到n-1移动到柱3；
递归时，大堆的to,from,inter分别是
3，1，2还有2，3，1

*/


void moved(int count,char C,char A,char B){
    if(count==0)return;
    else{
        moved(count-1,B,A,C);
        cout<<A<<"->"<<C<<endl;
       
        moved(count-1,C,B,A);


    }

}

int main(){
    int n;
    cin>>n;
    cout<<pow(2,n)-1<<endl;
    moved(n,'C','A','B');
    
}

