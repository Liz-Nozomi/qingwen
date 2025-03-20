#include <bits/stdc++.h>
#include <iostream>
#include <random>
#include <chrono>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    for (int iter = 0; iter < 100000; iter++)
    {
        shuffle(a.begin(), a.end(), rng);
        for (int i = 1; i <= n - 1; i++)
        {
            int u = 0, v = 0;
            for (int j = 0; j < i; j++)
            {
                u = u * 10 + a[j];
            }
            for (int j = i; j < n; j++)
            {
                v = v * 10 + a[j];
            }
            if (u * v == k)
            {
                if (u > v)
                {
                    int temp = u;
                    u = v;
                    v = temp;
                }
                cout << u << " " << v << endl;
                return 0;
            }
        }
    }
    return 0;
}