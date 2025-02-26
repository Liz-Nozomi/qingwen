#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000;

// 用结构体来表示每位弟子的全部信息
struct Student {
    int id;         // 编号（从 0 开始存储，但输出时要+1）
    int s[4];       // 四门仙科成绩
    int total;      // 四门成绩之和
    int admitted;   // 0 表示未录取，1 表示已录取
};

int n, m;
// students 用来存储所有弟子的结构体信息
Student students[MAXN];
int currentC; // 全局记录当前仙门的 c，用于比较函数

// 自定义排序函数
bool compareDisc(const Student &a, const Student &b) {
    // 先比总分
    if (a.total != b.total) {
        return a.total > b.total;
    }
    // 若总分相同且 c != 0，就比第 c 门分数
    if (currentC != 0) {
        if (a.s[currentC - 1] != b.s[currentC - 1]) {
            return a.s[currentC - 1] > b.s[currentC - 1];
        }
    }
    // 若依然相同，就比编号
    return a.id < b.id;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        students[i].id = i;
        for (int j = 0; j < 4; j++) {
            cin >> students[i].s[j];
        }
        students[i].total = students[i].s[0] + students[i].s[1]
                           + students[i].s[2] + students[i].s[3];
        students[i].admitted = 0;
    }

    for (int gate = 0; gate < m; gate++) {
        int k, c;
        cin >> k >> c;
        currentC = c;  // 用于排序比较时参考

        // 收集所有尚未被录取的弟子
        Student unadm[MAXN];
        int countUnadm = 0;
        for (int i = 0; i < n; i++) {
            if (students[i].admitted == 0) {
                unadm[countUnadm++] = students[i];
            }
        }

        // 对未录取的弟子进行排序
        sort(unadm, unadm + countUnadm, compareDisc);

        // 开始挑选录取名单
        Student chosen[MAXN];
        int countChosen = 0;

        if (countUnadm <= k) {
            // 不足 k 人，全部录取
            for (int i = 0; i < countUnadm; i++) {
                chosen[countChosen++] = unadm[i];
            }
        } else {
            // 先拿前 k 人
            for (int i = 0; i < k; i++) {
                chosen[countChosen++] = unadm[i];
            }
            // 检查并列
            Student last = unadm[k - 1];
            for (int i = k; i < countUnadm; i++) {
                bool tie = false;
                if (unadm[i].total == last.total) {
                    if (c != 0) {
                        if (unadm[i].s[c - 1] == last.s[c - 1]) {
                            tie = true;
                        }
                    } else {
                        tie = true; // c == 0 时只看总分
                    }
                }
                if (tie) {
                    chosen[countChosen++] = unadm[i];
                } else {
                    break;
                }
            }
        }

        // 输出并标记这些弟子为已录取
        cout << countChosen;
        for (int i = 0; i < countChosen; i++) {
            // 根据 chosen[i].id 找到原数组并标记
            int idx = chosen[i].id;
            students[idx].admitted = 1;
            // 输出时记得编号 +1
            cout << " " << (idx + 1);
        }
        cout << "\n";
    }

    return 0;
}