#include <iostream>
using namespace std;
#define A 100
int main() {
    int a[A];
    int n=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);

    }
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
        if(i<n-1){
            printf(" ");
        }
    }
} 