#include <cstdio>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int MAX_STEP = 16;
const int MAXD = 4;
int dx[MAXD] = {1, -1, 0, 0};
int dy[MAXD] = {0, 0, 1, -1};

int BFS(vector<vector<int>> s, vector<vector<int>> t) {
    map<vector<vector<int>>, bool> inQueue; // 用于记录状态是否已经访问过
    queue<vector<vector<int>>> q; // BFS队列
    q.push(s); // 将初始状态加入队列
    inQueue[s] = true; // 标记初始状态为已访问
    int step = 0; // 记录当前步数
    while (!q.empty() && step <= MAX_STEP) { // 当队列不为空且步数不超过16时继续搜索
        int cnt = q.size(); // 当前层的状态数量
        while (cnt--) { // 遍历当前层的所有状态
            vector<vector<int>> front = q.front(); // 取出队首状态
            q.pop();
            if (front == t) { // 如果当前状态等于目标状态，返回步数
                return step;
            }
            int x, y;
            for (int i = 0; i < 3; i++) { // 找到空白块的位置
                for (int j = 0; j < 3; j++) {
                    if (front[i][j] == 0) {
                        x = i, y = j;
                    }
                }
            }
            for (int i = 0; i < MAXD; i++) { // 尝试将空白块与相邻的拼图块交换
                int nextX = x + dx[i];
                int nextY = y + dy[i];
                if (nextX >= 0 && nextX < 3 && nextY >= 0 && nextY < 3) { // 检查新位置是否合法
                    vector<vector<int>> nextState = front; // 生成新状态
                    swap(nextState[x][y], nextState[nextX][nextY]); // 交换空白块和相邻拼图块
                    if (!inQueue[nextState]) { // 如果新状态未被访问过
                        q.push(nextState); // 加入队列
                        inQueue[nextState] = true; // 标记为已访问
                    }
                }
            }
        }
        step++; // 步数加1
    }
    return -1; // 如果无法在16步内完成，返回-1
}

int main() {
    vector<vector<int>> s(3, vector<int>(3)), t(3, vector<int>(3)); // 初始状态和目标状态
    for (int i = 0; i < 3; i++) { // 读取初始状态
        for (int j = 0; j < 3; j++) {
            scanf("%d", &s[i][j]);
        }
    }
    for (int i = 0; i < 3; i++) { // 读取目标状态
        for (int j = 0; j < 3; j++) {
            scanf("%d", &t[i][j]);
        }
    }
    printf("%d", BFS(s, t)); // 输出结果
    return 0;
}