#include <bits/stdc++.h>

using namespace std;

const int MAX_LIMIT = 500000; // 假设n的最大可能值为1e6，因此n/2最大为5e5
bool is_prime[MAX_LIMIT + 1];
int pre[MAX_LIMIT + 1];

void sieve()
{
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAX_LIMIT; ++i)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= MAX_LIMIT; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    // 计算前缀和数组
    pre[0] = 0;
    for (int i = 1; i <= MAX_LIMIT; ++i)
    {
        pre[i] = pre[i - 1] + (is_prime[i] ? 1 : 0);
    }
}

int main()
{
    sieve(); // 预处理质数和前缀和数组
    int n;
    cin >> n;
    int cnt = 0;

    // 处理形如2^3=8的情况
    if (n >= 8)
    {
        cnt += 1;
    }

    // 处理形如2*q的情况，其中q是奇质数且2*q <=n → q <=n/2
    int m = n / 2;
    if (m >= 2)
    {
        // 前缀和数组pre[m]表示小于等于m的质数个数，其中包含2
        // 所以奇质数的个数是pre[m] - 1（减去2的情况）
        cnt += (pre[m] - 1);
    }

    cout << cnt << endl;
    return 0;
}