#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char str1[101];
    cin.getline(str1,100);
    int a,b,c;
    if(sscanf(str1,"%d is greater than %d",&a,&b)==2){
        if(a>b){printf("Yes");}else{printf("No");}

    }else if(sscanf(str1, "%d is equal to %d plus %d", &a, &b, &c) == 3){
        if(a==b+c){printf("Yes");}else{printf("No");}
    }else{
        printf("???");
    } 
}