#include <bits/stdc++.h>
using namespace std;

class BIT{
    private:
        int n;
    public:
        int lowbit(int x){
            return x & (-x);
        }
};
int main(){
    int n;
    cin>>n;
    BIT t;
    cout<<t.lowbit(n);
}