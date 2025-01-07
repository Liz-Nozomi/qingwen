#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int num1,num2;
    scanf("%d %d",&num1,&num2);
    int res1=num1/num2;
    float res2=static_cast<float>(num1)/num2;
    cout<<res1<<endl;
    cout<<std::fixed << std::setprecision(2)<<res2<<endl;
}