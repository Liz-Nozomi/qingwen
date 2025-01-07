#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
    double num1;
    scanf("%lf",&num1);
    printf("%.2f %.0f %.0f %.0f %.2f",fabs(num1),floor(num1),ceil(num1),round(num1),pow(num1,5));

    }