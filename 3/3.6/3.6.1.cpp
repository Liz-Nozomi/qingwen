#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    cin>>str;
    string backup=str;
    int l=0,r=str.length()-1;
    //cout<<l<<r<<endl;
    while(l!=r & l!=r+1){
        swap(str[l],str[r]);
        
        l++;r--;
    }
    //cout<<str<<endl;
    if(backup==str){
        cout<<"YES"<<endl;

    }else cout<<"NO"<<endl;

}
