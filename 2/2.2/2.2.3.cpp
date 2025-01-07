#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    float num;
    scanf("%f",&num);
    cout<<std::fixed << std::setprecision(2)<<num<<endl;
}