#include <cstdio>
#include <string>
using namespace std;

string fillPrefixZero(int n) {
    if (n > 10) {
        return to_string(n);
    } else {
        return "0" + to_string(n);
    }
}

int main() {
    int yyyy, mm, dd, hh, mi, ss;
    scanf("%d-%d-%d %d:%d:%d", &yyyy, &mm, &dd, &hh, &mi, &ss);
    printf("%s\n", to_string(yyyy).c_str());
    printf("%s\n", fillPrefixZero(mm).c_str());
    printf("%s\n", fillPrefixZero(dd).c_str());
    printf("%s\n", fillPrefixZero(hh).c_str());
    printf("%s\n", fillPrefixZero(mi).c_str());
    printf("%s", fillPrefixZero(ss).c_str());
    return 0;
}