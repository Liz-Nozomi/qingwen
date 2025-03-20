// #include <iostream>
// #include <vector>
// #include <set>
// #include <algorithm>
// using namespace std;

// typedef pair<int, int> pii;

// struct Student {
//     vector<int> school; // 志愿学校
//     vector<int> qualified; // 加分后总分
//     set<int> friends; // 好友列表
//     vector<int> luqu; // 拟录取学校列表
//     int math, writing, basic_grade, final_selected = -1; // 数学成绩、学术写作成绩、基础总分、最终录取学校
// } students[1000];

// struct School {
//     int num, bonus, threshold, min_num; // 录取人数上限、加分、加分门槛、最低录取分
//     vector<pii> qualifiedStudent; // 合格学生列表（加分后总分，学生编号）
// } schools[100];

// // 排序规则
// bool cmp(const pii& a, const pii& b) {
//     int x = a.second, y = b.second;
//     if (a.first == b.first) {
//         if (students[x].math == students[y].math) {
//             if (students[x].writing == students[y].writing) {
//                 return x < y;
//             }
//             return students[x].writing > students[y].writing;
//         }
//         return students[x].math > students[y].math;
//     }
//     return a.first > b.first;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, m, k, p, temp;
//     cin >> n >> m >> k;
//     for (int i = 0; i < m; i++) {
//         cin >> students[i].math >> students[i].writing;
//         students[i].basic_grade = students[i].math + students[i].writing;
//     }
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < k; j++) {
//             cin >> temp;
//             temp--;
//             students[i].school.push_back(temp);
//         }
//     }
//     cin >> p;
//     for (int i = 0; i < p; i++) {
//         int u, v;
//         cin >> u >> v;
//         u--;
//         v--;
//         students[u].friends.insert(v);
//         students[v].friends.insert(u);
//     }
//     for (int i = 0; i < n; i++) {
//         cin >> schools[i].num >> schools[i].bonus >> schools[i].threshold;
//     }
//     for (int i = 0; i < m; i++) {
//         set<int> temp_friend = students[i].friends;
//         vector<int> lesson = students[i].school;
//         for (int j = 0; j < lesson.size(); j++) {
//             bool flag = false;
//             int g = lesson[j];
//             for (int f:temp_friend) {
//                 vector<int> tt = students[f].school;
//                 if (find(tt.begin(), tt.end(), g) != tt.end() && students[f].basic_grade >= schools[g].threshold) {
//                     flag = true;
//                     break;
//                 }
//             }
//             if (flag || students[i].basic_grade >= schools[g].threshold) {
//                 students[i].qualified.push_back(students[i].basic_grade + schools[g].bonus);
//             } else {
//                 students[i].qualified.push_back(students[i].basic_grade);
//             }
//         }
//     }
//     for (int i = 0; i < m; i++) {
//         vector<int> p = students[i].school;
//         vector<int> q = students[i].qualified;
//         for (int j = 0; j < p.size(); j++) {
//             schools[p[j]].qualifiedStudent.push_back(pii(q[j], i));
//         }
//     }
//     for (int i = 0; i < n; i++) {
//         sort(schools[i].qualifiedStudent.begin(), schools[i].qualifiedStudent.end(), cmp);
//         vector<pii> tt = schools[i].qualifiedStudent;
//         int nn = schools[i].num;
//         vector<pii> admitted;
//         if (!tt.empty()) {
//             int actualAdmit = min(nn, (int)tt.size());
//             for (int j = 0; j < actualAdmit; j++) {
//                 admitted.push_back(tt[j]);
//                 students[tt[j].second].luqu.push_back(i);
//             }
//             const pii& lastAdmitted = tt[actualAdmit-1];
//             int currentIndex = actualAdmit;
//             while (currentIndex < tt.size() && tt[currentIndex].first == lastAdmitted.first &&
//                    students[tt[currentIndex].second].math == students[lastAdmitted.second].math &&
//                    students[tt[currentIndex].second].writing == students[lastAdmitted.second].writing) {
//                 admitted.push_back(tt[currentIndex]);
//                 students[tt[currentIndex].second].luqu.push_back(i);
//                 currentIndex++;
//             }
//             schools[i].min_num = lastAdmitted.first;
//         }
//         schools[i].qualifiedStudent = admitted;
//     }
//     for (int i = 0; i < m; i++) {
//         vector<int> lu = students[i].luqu;
//         int selected = -1, maN = -1;
//         for (int ttt : lu) {
//             if (schools[ttt].min_num > maN) {
//                 selected = ttt;
//                 maN = schools[ttt].min_num;
//             } else if (schools[ttt].min_num == maN) {
//                 selected = min(selected, ttt);
//             }
//         }
//         students[i].final_selected = selected;
//     }
//     vector<vector<int>> result(n);
//     for (int i = 0; i < m; i++) {
//         int llu = students[i].final_selected;
//         if (llu != -1) {
//             result[llu].push_back(i);
//         }
//     }
//     for (int i = 0; i < n; i++) {
//         vector<int> qp = result[i];
//         sort(qp.begin(), qp.end());
//         cout << "School " << i + 1 << ":";
//         for (int qq : qp) {
//             cout << " " << qq + 1;
//         }
//         cout << endl;
//     }
//     return 0;
// }


#include <iostream>
#include <vector>
#include<set>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

struct Student {
    vector<int> school; // 志愿学校
    vector<int> qualified; // 加分后总分
    set<int> friends; // 好友列表
    vector<int> luqu; // 拟录取学校列表
    int math, writing, basic_grade, final_selected = -1; // 数学成绩、学术写作成绩、基础总分、最终录取学校
} students[1000];

struct School {
    int num, bonus, threshold, min_num; // 录取人数上限、加分、加分门槛、最低录取分
    vector<pii> qualifiedStudent; // 合格学生列表（加分后总分，学生编号）
} schools[100];

// 选择拟录取学生
vector<pii> select(int i, vector<pii> tt, int nn) {
    vector<pii> admitted;
    if (!tt.empty()) {
        int actualAdmit = min(nn, (int)tt.size());
        for (int j = 0; j < actualAdmit; j++) {
            admitted.push_back(tt[j]);
            students[tt[j].second].luqu.push_back(i);
        }
        const pii& lastAdmitted = tt[actualAdmit-1];
        int currentIndex = actualAdmit;
        while (currentIndex < tt.size() && tt[currentIndex].first == lastAdmitted.first &&students[tt[currentIndex].second].math == students[lastAdmitted.second].math &&students[tt[currentIndex].second].writing == students[lastAdmitted.second].writing) {
            admitted.push_back(tt[currentIndex]);
            students[tt[currentIndex].second].luqu.push_back(i);
            currentIndex++;
        }
        schools[i].min_num = lastAdmitted.first;
    }
    return admitted;
}

// 排序规则
bool cmp(const pii& a, const pii& b) {
    int x = a.second, y = b.second;
    if (a.first == b.first) {
        if (students[x].math == students[y].math) {
            if (students[x].writing == students[y].writing) {
                return x < y;
            }
            return students[x].writing > students[y].writing;
        }
        return students[x].math > students[y].math;
    }
    return a.first > b.first;
}

int main() {
    int n, m, k, p, temp;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        cin >> students[i].math >> students[i].writing;
        students[i].basic_grade = students[i].math + students[i].writing;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> temp;
            temp--;
            students[i].school.push_back(temp);
        }
    }
    cin >> p;
    for (int i = 0; i < p; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        students[u].friends.insert(v);
        students[v].friends.insert(u);
    }
    for (int i = 0; i < n; i++) {
        cin >> schools[i].num >> schools[i].bonus >> schools[i].threshold;
    }
    for (int i = 0; i < m; i++) {
        set<int> temp_friend = students[i].friends;
        vector<int> lesson = students[i].school;
        for (int j = 0; j < lesson.size(); j++) {
            bool flag = false;
            int g = lesson[j];
            for (int f:temp_friend) {
                vector<int> tt = students[f].school;
                if (find(tt.begin(), tt.end(), g) != tt.end() && students[f].basic_grade >= schools[g].threshold) {
                    flag = true;
                    break;
                }
            }
            if (flag || students[i].basic_grade >= schools[g].threshold) {
                students[i].qualified.push_back(students[i].basic_grade + schools[g].bonus);
            } else {
                students[i].qualified.push_back(students[i].basic_grade);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        vector<int> p = students[i].school;
        vector<int> q = students[i].qualified;
        for (int j = 0; j < p.size(); j++) {
            schools[p[j]].qualifiedStudent.push_back(pii(q[j], i));
        }
    }
    for (int i = 0; i < n; i++) {
        sort(schools[i].qualifiedStudent.begin(), schools[i].qualifiedStudent.end(), cmp);
        vector<pii> tt = schools[i].qualifiedStudent;
        int nn = schools[i].num;
        vector<pii> value = select(i, tt, nn);
        schools[i].qualifiedStudent = value;
    }
    for (int i = 0; i < m; i++) {
        vector<int> lu = students[i].luqu;
        int selected = -1, maN = -1;
        for (int ttt : lu) {
            if (schools[ttt].min_num > maN) {
                selected = ttt;
                maN = schools[ttt].min_num;
            } else if (schools[ttt].min_num == maN) {
                selected = min(selected, ttt);
            }
        }
        students[i].final_selected = selected;
    }
    vector<vector<int>> result(n);
    for (int i = 0; i < m; i++) {
        int llu = students[i].final_selected;
        if (llu != -1) {
            result[llu].push_back(i);
        }
    }
    for (int i = 0; i < n; i++) {
        vector<int> qp = result[i];
        if (qp.empty()) {
            cout << "School " << i + 1 << ":" << endl;
        } else {
            cout << "School " << i + 1 << ":";
            for (int qq : qp) {
                cout << " " << qq + 1;
            }
            cout << endl;
        }
    }
    return 0;
}