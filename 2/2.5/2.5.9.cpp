#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char str1[100],str2[100];
    cin.getline(str1,100);
    cin.getline(str2,100);
    int cmp=strcmp(str1,str2);
    if(cmp>1){
        printf(">");
        
    }else if(cmp==0){printf("=");}else printf("<");
}