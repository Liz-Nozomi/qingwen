#include <iostream>
#include <utility>
using namespace std;
#define A 100
int main() {
    int a[A];
    int n=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);

    }
    for (int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(a[j]>a[j+1])swap(a[j],a[j+1]);
        }
    }
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
        if(i<n-1){
            printf(" ");
        }
    }
}
