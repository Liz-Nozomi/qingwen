#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 1000;

struct Student {
    string name;
    int score, rank;
} stu[MAXN];

bool cmpScore(Student a, Student b) {
    return a.score > b.score;
}

bool cmpName(Student a, Student b) {
    return a.name < b.name;
}

int main() {
    int n, stuCount = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            cin >> stu[stuCount + j].name >> stu[stuCount + j].score;
        }
        sort(stu + stuCount, stu + stuCount + k, cmpScore);
        stu[stuCount].rank = 1;
        for (int j = stuCount + 1; j < stuCount + k; j++) {
            if (stu[j].score == stu[j - 1].score) {
                stu[j].rank = stu[j - 1].rank;
            } else {
                stu[j].rank = j - stuCount + 1;
            }
        }
        stuCount += k;
    }
    sort(stu, stu + stuCount, cmpName);
    for (int i = 0; i < stuCount; i++) {
        cout << stu[i].name << " " << stu[i].score << " " << stu[i].rank << endl;
    }
    return 0;
}