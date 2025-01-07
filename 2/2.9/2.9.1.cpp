
#include <iostream>
#include <iomanip>
using namespace std;

const int MAXN = 110;
char str[MAXN];

int main() {
    int n;
    double d;
    cin >> n >> d;
    getchar();
    cin.getline(str, MAXN);
    cout << n << endl;
    cout << setiosflags(ios::fixed) << setprecision(2) << d << endl;
    cout << str;
    return 0;
}