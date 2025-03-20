#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<pair<int, int> > books;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        books.push_back(make_pair(x,y));
    }

    vector<vector<int> > dp(101, vector<int>(101, INF));
    dp[0][0] = 0;

    for (auto book : books) {
        int x = book.first;
        int y = book.second;
        for (int i = 100; i >= 0; i--) {
            for (int j = 100; j >= 0; j--) {
                if (dp[i][j] != INF) {
                    int new_i = min(i + x, 100);
                    int new_j = min(j + y, 100);
                    if (dp[new_i][new_j] > dp[i][j] + 1) {
                        dp[new_i][new_j] = dp[i][j] + 1;
                    }
                }
            }
        }
    }

    int result = INF;
    for (int i = a; i <= 100; i++) {
        for (int j = b; j <= 100; j++) {
            if (dp[i][j] < result) {
                result = dp[i][j];
            }
        }
    }

    cout << (result == INF ? -1 : result) << endl;

    return 0;
}