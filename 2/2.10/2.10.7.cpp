#include <iostream>
#define N 1000
using namespace std;

int a[N];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        printf("%d", a[i] + 1);
        if (i < n - 1)
        {
            printf(" ");
        }
    }
}