#include <iostream>
#include <string>
using namespace std;

int main () {
    string s1, s2;
    cin >> s1 >> s2;
    int pos = s1.find(s2);
    printf("%d", pos);
    return 0;
}