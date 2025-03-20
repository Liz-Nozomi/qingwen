#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    cin >> n >> a;
    vector<int> days(n);
    for (int i = 0; i < n; ++i) {
        cin >> days[i];
    }

    int left = 0, maxLen = 0, workCount = 0;

    for (int right = 0; right < n; ++right) {
        if (days[right] == 1) {
            ++workCount;
        }

        while (workCount > a) {
            if (days[left] == 1) {
                --workCount;
            }
            ++left;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    cout << maxLen << endl;
    return 0;
}
//前缀和就能做，比这个方便点，但是来不及了