#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    multimap<int, int> x; // 按x坐标排序，value为y坐标
    multimap<int, int> y; // 按x坐标排序，value为y坐标

    unordered_map<int, unordered_map<int, bool> > point_map; // 用于快速查找点是否存在
    vector<pair<int, int> > points;
    for (int i = 0; i < n; i++) {
        int px, py;
        cin >> px >> py;
        x.insert(make_pair(px, py));
        y.insert(make_pair(py,px));
        point_map[px][py] = true;
        points.push_back(make_pair(px, py));
    }

    int count = 0;
    
    for(auto it:points){
        int x1 = it.first;
        int y1 = it.second;

        auto range = x.equal_range(x1);
        for(auto y2 = range.first;y2 != range.second;y2++){
            if(y2->second > y1){
                auto range2 = y.equal_range(y1);
                for(auto x2 = range2.first;x2 != range2.second;x2++){

                    if(x2->second > x1){
                        if(point_map[x2->second][y2->second]){
                            count++;
                        }
                    }
                }


            }
        }

    }
    cout << count << endl;

    return 0;
}