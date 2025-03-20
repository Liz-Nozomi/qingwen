#include <bits/stdc++.h>


using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c; // 从评测平台获取输入的三个数字
    random_device rd;
    mt19937 gen(rd());
    // 定义范围在[0, 300]的均匀分布
    std::uniform_int_distribution<> dis(0, 300);
    vector<int> rndnum;
    for(int i=0;i<3;i++){
        rndnum.push_back(dis(gen));
    }
    cout<<rndnum[0]<<" "<<rndnum[1]<<" "<<rndnum[2];
}