#include <iostream>
#include <utility>
using namespace std;
#define A 100
#define B 100
int main(){
    int a[A][B];
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d",a[i][j]);
            if(j<m-1)printf(" ");
        }
        printf("\n");
    }
}