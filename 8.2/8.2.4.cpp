#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> Position;

const int MAXN = 100;
int n, m, maze[MAXN][MAXN];
bool inQueue[MAXN][MAXN] = {false};
Position pre[MAXN][MAXN];

const int MAXD = 4;
int dx[MAXD] = {0, 0, 1, -1};
int dy[MAXD] = {1, -1, 0, 0};

bool canVisit(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 0 && !inQueue[x][y];
}

void BFS(int x, int y) {
    queue<Position> q;
    q.push(Position(x, y));
    inQueue[x][y] = true;
    while (!q.empty()) {
        Position front = q.front();
        q.pop();
        if (front.first == n - 1 && front.second == m - 1) {
            return;
        }
        for (int i = 0; i < MAXD; i++) {
            int nextX = front.first + dx[i];
            int nextY = front.second + dy[i];
            if (canVisit(nextX, nextY)) {
                pre[nextX][nextY] = Position(front.first, front.second);
                inQueue[nextX][nextY] = true;
                q.push(Position(nextX, nextY));
            }
        }
    }
}

void printPath(Position p) {
    Position prePosition = pre[p.first][p.second];
    if (prePosition == Position(-1, -1)) {
        printf("%d %d\n", p.first + 1, p.second + 1);
        return;
    }
    printPath(prePosition);
    printf("%d %d\n", p.first + 1, p.second + 1);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &maze[i][j]);
        }
    }
    fill(pre[0], pre[0] + n * m, Position(-1, -1));
    BFS(0, 0);
    printPath(Position(n - 1, m - 1));
    return 0;
}