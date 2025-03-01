#include <bits/stdc++.h>
using namespace std;
/* TLE hahaha
struct numpair{
    int a;
    int b;
    int delta[4];
    numpair(int _a,int _b){
        a = _a;
        b = _b;
        delta[0] = a+b;
        delta[1] = a-b;
        delta[2] = b-a;
        delta[3] = -b-a;
    }
};

bool cmp0(numpair a,numpair b){
    return a.delta[0] > b.delta[0];
}
bool cmp1(numpair a,numpair b){
    return a.delta[1] > b.delta[1];
}
bool cmp2(numpair a,numpair b){
    return a.delta[2] > b.delta[2];
}
bool cmp3(numpair a,numpair b){
    return a.delta[3] > b.delta[3];
}

int main(){
    int n,k;
    cin>>n>>k;
    priority_queue<numpair,vector<numpair>,decltype(&cmp0)> pq0(cmp0);
    priority_queue<numpair,vector<numpair>,decltype(&cmp1)> pq1(cmp1);
    priority_queue<numpair,vector<numpair>,decltype(&cmp2)> pq2(cmp2);
    priority_queue<numpair,vector<numpair>,decltype(&cmp3)> pq3(cmp3);


    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        numpair np(a, b);

        if(pq0.size() < k){
            pq0.push(numpair(a,b));
            pq1.push(numpair(a,b));
            pq2.push(numpair(a,b));
            pq3.push(numpair(a,b));
        }
        else{
               if (np.delta[0] > pq0.top().delta[0]) {
                pq0.pop();
                pq0.push(np);
            }
            if (np.delta[1] > pq1.top().delta[1]) {
                pq1.pop();
                pq1.push(np);
            }
            if (np.delta[2] > pq2.top().delta[2]) {
                pq2.pop();
                pq2.push(np);
            }
            if (np.delta[3] > pq3.top().delta[3]) {
                pq3.pop();
                pq3.push(np);
            }
        }

    }

    int sum0 = 0;
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;

    for(int i=0;i<k;i++){
        sum0 += pq0.top().delta[0];
        pq0.pop();
        sum1 += pq1.top().delta[1];
        pq1.pop(); 
        sum2 += pq2.top().delta[2];
        pq2.pop(); 
        sum3 += pq3.top().delta[3];
        pq3.pop();

    }
    //cout<<sum0<<sum2<<sum3;
    cout<< max(sum0, max(sum1, max(sum2,sum3)));


}
*/
typedef long long LL;
const int MAXN = 100000;
int a[MAXN], b[MAXN], c[MAXN];
int op[2] = {-1, 1};

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i], &b[i]);
    }
    LL result = 0;
    for (int opA = 0; opA < 2; opA++) {
        for (int opB = 0; opB < 2; opB++) {
            for (int i = 0; i < n; i++) {
                c[i] = op[opA] * a[i] + op[opB] * b[i];
            }
            sort(c, c + n, greater<int>());
            LL sum = 0;
            for (int i = 0; i < k; i++) {
                sum += c[i];
            }
            result = max(result, sum);
        }
    }
    printf("%lld", result);
    return 0;
}