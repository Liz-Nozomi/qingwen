#include <bits/stdc++.h>
using namespace std;

struct firstthree{
    vector<int> f3;
};

int main(){
    int n,m;//n 颜色数量 m圆柱数量
    //颜色数量用来哈希。
    vector< queue<int> > bottles(m);
    int spherecount = 0;
    for(int i=0;i<m;i++){
        int cnt;
        cin>>cnt;
        spherecount += cnt;
        queue<int> tq;
        for(int j=0;j<cnt;j++){
            int t;
            cin>>t;
            tq.push(t);
        }
        bottles[i] = tq;
    }
    
    //for one round
            vector<firstthree> hashmap(n+1);
            set<int> colors_enough_3;
            for(int i=0;i<m;i++){
                if(!bottles[i].empty()){//bottles[i].front() 顶颜色
                    //hashmap[上面一坨] 存着前三个这个颜色的位置
                    if(hashmap[bottles[i].front()].f3.size() < 3){
                        hashmap[bottles[i].front()].f3.push_back(i);
                        if(hashmap[bottles[i].front()].f3.size() == 3){
                            colors_enough_3.insert(bottles[i].front());
                        }
                    }
                }
            }
            int selectedcolor = *colors_enough_3.begin();
            bottles[hashmap[selectedcolor].f3[0]].pop();
            bottles[hashmap[selectedcolor].f3[1]].pop();
            bottles[hashmap[selectedcolor].f3[2]].pop();

            cout<<selectedcolor;
     
}