#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
    int num1;
    scanf("%d",&num1);
    switch (num1){ 
        case 0:printf("Zero");break;
        case 1:printf("One");break;
        case 2:printf("Two");break;
        case 3:printf("Three");break;
        case 4:printf("Four");break;
        case 5:printf("Five");break;
        default:printf("Greater than 5");
    }
}