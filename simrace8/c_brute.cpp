#include <bits/stdc++.h>
using namespace std;

struct firstthree {
    vector<int> f3;
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<queue<int> > bottles(m);
    vector<int> res;
    for (int i = 0; i < m; ++i) {
        int cnt;
        cin >> cnt;
        queue<int> tq;
        for (int j = 0; j < cnt; ++j) {
            int t;
            cin >> t;
            tq.push(t);
        }
        bottles[i] = tq;
    }

    while (true) {
        vector<firstthree> hashmap(n + 1);
        set<int> colors_enough_3;

        // 构建哈希表和集合
        for (int i = 0; i < m; ++i) {
            if (!bottles[i].empty()) {
                int color = bottles[i].front();
                if (hashmap[color].f3.size() < 3) {
                    hashmap[color].f3.push_back(i);
                    if (hashmap[color].f3.size() == 3) {
                        colors_enough_3.insert(color);
                    }
                }
            }
        }

        if (colors_enough_3.empty()) {
            break; // 无法继续处理
        }
        int selectedcolor = *colors_enough_3.begin();

        // 弹出三个颜色块
        vector<int> indices = hashmap[selectedcolor].f3;
        for (int idx : indices) {
            if (!bottles[idx].empty()) {
                bottles[idx].pop();
            }
        }
        res.push_back(selectedcolor);
        colors_enough_3.erase(selectedcolor);

    }
    int temp = 0;
    for(auto it:res){
        cout<<it;
        temp++;
        if(temp < res.size()){
            cout<<" ";
        }
    }
    //纯纯暴力 很慢
}