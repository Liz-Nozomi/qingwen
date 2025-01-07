#include <iostream>
#include <algorithm>
using namespace std;
#define N 110
int main(){
    int A[N];
    int count[N]={0};
    int n;
    int x;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
        count[A[i]]++;
    }
    scanf("%d",&x);
    printf("%d",count[x]);
}