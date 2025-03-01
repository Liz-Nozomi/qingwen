#include <bits/stdc++.h>
using namespace std;


int getLIS(vector<int> a,int n) {
    vector<int> smallest;
    for (int i = 0; i < n; i++) {
        int upper = upper_bound(smallest.begin(), smallest.end(), a[i]) - smallest.begin();
        if (upper == smallest.size()) {
            smallest.push_back(a[i]);
        } else {
            smallest[upper] = a[i];
        }
    }
    return smallest.size();
}