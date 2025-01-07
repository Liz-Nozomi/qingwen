#include <iostream>
using namespace std;
int main() {
    int n, sum = 0;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            printf("%d",j);
            if(j<n-i+1){printf(" ");}
                else{printf("\n");}
        }
    }
} 