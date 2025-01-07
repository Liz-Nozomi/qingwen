#include<iostream>
#include<cstring>
using namespace std;
int increase(int n){
    n++;
    return n;
}
int main(){
    int n;
    scanf("%d",&n);
    int res=increase(n);
    cout<<res<<" "<<n<<endl;
}