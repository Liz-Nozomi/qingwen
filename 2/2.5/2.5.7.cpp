#include<iostream>
using namespace std;
int main(){
    char str[100];
    int n;
    scanf("%d",&n);
    cin.get();
    for(int i=0;i<n;i++){
        cin.getline(str,100);
        puts(str);
    }
    
    

}