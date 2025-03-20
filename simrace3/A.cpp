#include <bits/stdc++.h>
using namespace std;
int n;

vector<bool> is_prime;
vector<int> primes;

void getallin(int n,vector<int> &res){
    for(int i=1;i<=sqrt(n);i++){
        if(n % i == 0){
            res.push_back(i);
            if(i != n/i){
                res.push_back(n/i);
            }
        }
    }
    sort(res.begin(),res.end());
}


void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    // 计算前缀和数组
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

int getprimenums(int it) {
    int cnt = 0;
    for (int i = 0; primes[i] * primes[i] <= it; i++) { // 只需检查到 sqrt(it)
        if (it % primes[i] == 0) {
            cnt++;
            while (it % primes[i] == 0) { // 去掉所有当前质因数
                it /= primes[i];
            }
        }
    }
    if (it > 1) { // 如果 it > 1，说明 it 本身是一个质因数
        cnt++;
    }
    return cnt;
}
int main(){
    cin>>n;
    is_prime.resize(n+1,true);

    vector<int> res;
    getallin(n,res);
    sieve();
    vector<int> out;
    for(auto it:res){
        if(getprimenums(it) == 3){
            out.push_back(it);
        }
    }


    if(out.size() == 0){
        cout<<-1;
    }else{
        for(auto it2:out){
            cout<<it2<<endl;
        }
    }

}