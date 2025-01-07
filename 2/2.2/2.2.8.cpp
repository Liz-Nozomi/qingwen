#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int num1;
    scanf("%d",&num1);
    num1++;
    cout<<std::fixed << std::setprecision(2)<<num1<<endl;
}