#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    float num1;
    scanf("%f",&num1);
    float res=3.14*num1*2;
    cout<<std::fixed << std::setprecision(2)<<res<<endl;
}