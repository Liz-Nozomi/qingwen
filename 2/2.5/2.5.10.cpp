#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char str1[101],str2[101];
    cin.getline(str1,100);
    cin.getline(str2,100);
    strcat(str1,str2);
    puts(str1);
}