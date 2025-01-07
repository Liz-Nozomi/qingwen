#include <iostream>
#include<iomanip>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int i=0,sum=0;
    while(i<=n){
        sum+=i;
        i++;
        if(sum>2000)break;
    }
    cout<<sum<<endl;
}