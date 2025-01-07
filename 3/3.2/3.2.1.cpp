#include <iostream>
using namespace std;
#define N 100
int main()
{
    int n;
    int num[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    int search, queue, flag = 0;
    scanf("%d", &search);
    for (int i = 0; i < n; i++)
    {
        if (search == num[i])
        {
            queue = i;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("NO");
    }
    else
        printf("%d", queue + 1);
}