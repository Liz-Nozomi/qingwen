#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char str1[101];
    int yyyy, mm, dd, hh, mi, ss;
        scanf("%d%d%d%d%d%d", &yyyy, &mm, &dd, &hh, &mi, &ss);
        sprintf(str1, "%04d-%02d-%02d %02d:%02d:%02d", yyyy, mm, dd, hh, mi, ss);
        printf("%s", str1);
}