#include <cstdio>
#include <queue>
#include <utility>
#include <map>
using namespace std;

typedef pair<int, int> Position;

const int MAXN = 100;
int n, m, maze[MAXN][MAXN];
bool inQueue[MAXN][MAXN] = {false};
map<Position, Position> transMap;

const int MAXD = 4;
int dx[MAXD] = {0, 0, 1, -1};
int dy[MAXD] = {1, -1, 0, 0};

bool canVisit(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && (maze[x][y] == 0 || maze[x][y] == 2) && !inQueue[x][y];
}

int BFS(int x, int y) {
    queue<Position> q;
    q.push(Position(x, y));
    inQueue[x][y] = true;
    int step = 0;
    while (!q.empty()) {
        int cnt = q.size();
        while (cnt--) {
            Position front = q.front();
            q.pop();
            if (front.first == n - 1 && front.second == m - 1) {
                return step;
            }
            for (int i = 0; i < MAXD; i++) {
                int nextX = front.first + dx[i];
                int nextY = front.second + dy[i];
                if (canVisit(nextX, nextY)) {
                    inQueue[nextX][nextY] = true;
                    q.push(Position(nextX, nextY));
                    if (maze[nextX][nextY] == 2) {
                        Position transPosition = transMap[Position(nextX, nextY)];
                        inQueue[transPosition.first][transPosition.second] = true;
                        q.push(transPosition);
                    }
                }
            }
        }
        step++;
    }
    return -1;
}

int main() {
    vector<Position> transVector;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &maze[i][j]);
            if (maze[i][j] == 2) {
                transVector.push_back(Position(i, j));
            }
        }
    }
    transMap[transVector[0]] = transVector[1];
    transMap[transVector[1]] = transVector[0];
    int step = BFS(0, 0);
    printf("%d", step);
    return 0;
}