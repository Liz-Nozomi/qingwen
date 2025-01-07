#include<iostream>
#include<cstring>
using namespace std;
int max2(int a,int b){
    return max(a,b);

}
int max3(int a,int b,int c){
    int tmp=max2(a,b);
    return max2(tmp,c);
}
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    cout<<max3(a,b,c)<<endl;
}