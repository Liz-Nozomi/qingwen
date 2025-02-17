#include <bits/stdc++.h>
using namespace std;
struct Rectangle{
    int length;
    int width;
    Rectangle(int _l,int _w){
        length=_l;
        width=_w;
    }
    Rectangle(){}
};

bool compare(const Rectangle& a, const Rectangle& b) {
    if (a.length != b.length)
        return a.length < b.length;
    else
        return a.width > b.width;
}

int main(){
    int n;
    cin>>n;
    //int dp[1000];//dp[i] 表示以i结尾的矩形序列长度
    vector<Rectangle> recs;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(a<b){
            recs.push_back(Rectangle(a,b));

        }
        else{
            recs.push_back(Rectangle(b,a));
        }
    }
    sort(recs.begin(),recs.end(),compare);

    vector<int> dp(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if((recs[j].length < recs[i].length and recs[j].width < recs[i].width)or(recs[j].length < recs[i].width and recs[j].width < recs[i].length)){
                dp[i] = max(dp[i],dp[j]+1);
            }

        }
    }

    int res = *max_element(dp.begin(),dp.end());
    cout<<res;


}