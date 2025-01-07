#include <iostream>
int n;
int count;
int main(){
    scanf("%d",&n);
    while(n!=1){
        if(n%2==0){
            n=n/2;
        }else{
            n=(n*3+1)/2;
        }
        count++;
    }
    printf("%d",count);
}
