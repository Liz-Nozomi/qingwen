#include <bits/stdc++.h>


using namespace std;

using ll = long long;

set<ll> st;

void init() {
    ll i = 1;
    while(i * i <= 1000000000) {
        st.insert(i*i);
        i++;
    }
}

vector<ll> a;

bool dfs(int idx) {
    if (idx == a.size()) {
        return true;
    }
    ll c = 0;
    for (int i = idx; i < a.size(); i++) {
        c = c * 10 + a[i];
        if (st.count(c)) {
            if (dfs(i + 1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ll n;
    cin >> n;
    while(n) {
        a.push_back(n%10);
        n/=10;
    }
    init();
    reverse(a.begin(), a.end());
    if (dfs(0)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}