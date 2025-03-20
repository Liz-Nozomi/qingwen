#include <bits/stdc++.h>
using namespace std;

int findpairlocation(vector<string>& groups, string name) {
    for (int i = 0; i < groups.size(); i++) {
        if (groups[i] == name) {
            return i;
        }
    }
    return -1; // 添加返回值，避免未找到时出现问题
}

int main() {
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<string> groups(n * 2);
    map<string, string> pairs;

    for (int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        groups[2 * i] = s1;
        groups[2 * i + 1] = s2;
        pairs[s1] = s2;
        pairs[s2] = s1;
    }

    int cs = 0;  // 当前使用者的位置
    vector<string> res;

    for (int i = 0; i < q; i++) {
        char cmd;
        cin >> cmd;
        if (cmd == 'G') {
            if (cs == 0) {
                cs = 2 * n - 1;  // 如果当前是队首，传给队尾
            } else {
                cs--;  // 否则，传给前一位
            }
        }

        if (cmd == 'H') {
            if (cs == 2 * n - 1) {
                cs = 0;  // 如果当前是队尾，传给队首
            } else {
                cs++;  // 否则，传给后一位
            }
        }

        if (cmd == 'I') {
            int temp = cs;
            string tname = groups[temp];
            if (cs == 2 * n - 1) {
                cs = 0;  // 如果是最后一位，移动到队首
            } else {
                // 这里不需要改变 cs
            }
            groups.erase(groups.begin() + temp);  // 删除当前元素
            groups.push_back(tname);  // 将其放到队尾
        }

        if (cmd == 'J') {
            int temp = cs;
            string tname = groups[temp];
            int partnerPos = findpairlocation(groups, tname);  // 找到当前人的搭档位置

            if (cs == 2 * n - 1) {
                cs = 0;  // 如果是队尾，转到队首
            }

            // 根据搭档位置，进行相应的插入
            if (partnerPos < cs) {
                groups.erase(groups.begin() + temp);
                groups.insert(groups.begin() + partnerPos + 1, tname);  // 插入到搭档后面
            } else {
                groups.erase(groups.begin() + temp);
                groups.insert(groups.begin() + partnerPos + 1, tname);  // 插入到搭档后面
            }
        }

        if (cmd == 'K') {
            res.push_back(pairs[groups[cs]]);  // 记录当前使用者的搭档
        }
    }

    for (const auto& s : res) { 
        cout << s << endl;  // 输出所有记录的搭档名字
    }
    
    // 打印队列中的所有元素
    for (auto it : groups) {
        cout << it << endl;
    }

    return 0;
}
