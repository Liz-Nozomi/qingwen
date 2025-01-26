#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    int n, k;
    cin >> n;
    string action;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        cin >> action;
        if (action == "push") {
            cin >> k;
            q.push(k);
        } else {
            if (q.empty()) {
                cout << -1 << endl;
            } else {
                cout << q.front() << endl;
                q.pop();
            }
        }
    }
    return 0;
}