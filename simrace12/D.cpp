#include <bits/stdc++.h>
using namespace std;
struct path{
    int from;
    int to;
    int d;
};
const int INF = 1e9;
int T;
int s,t;
int dist[10010][10010];
vector<int> occupied;
vector< vector<path> > graph;
bool visited[100010];
vector<int> trypath;
int maxd = 0;

void dfs(int current,int currentdist){
    if(current == t){//结束
        if(currentdist <= T){
            int min_maxd = INT_MAX;
            for(auto it:trypath){
                for(auto it2:occupied){
                    min_maxd = min(min_maxd,dist[it][it2]);
                }
            }

            maxd = max(min_maxd,maxd);
        }
        return;
    }

    for (auto &p : graph[current]) { // 遍历当前节点的所有邻接点
        if (!visited[p.to]) { // 如果邻接点未被访问过
            if (currentdist + dist[current][p.to] <= T) { // 如果加上到邻接点的距离后总距离仍小于T
                visited[p.to] = true; // 标记邻接点为已访问
                trypath.push_back(p.to); // 将邻接点加入路径
                dfs(p.to, currentdist+dist[current][p.to]); // 递归搜索邻接点
                trypath.pop_back(); // 回溯，移除邻接点
                visited[p.to] = false; // 标记邻接点为未访问
            }
        }
    }


}


int main(){
    //最小的最大，我觉得这是个二分
    //好吧不是
    int n,m;

    cin>>n>>m>>T;//营地 路 时间
    graph.resize(n);
    for(int i=0;i<m;i++){
        path p;
        cin>>p.from>>p.to>>p.d;
        graph[p.from].push_back(p);
        graph[p.to].push_back(p);
    }

    cin>>s>>t;

    int k;
    cin>>k;
    memset(visited,false,sizeof(bool));
    for(int i=0;i<k;i++){
        int temp;
        cin>>temp;
        occupied.push_back(temp);
    }

    sort(occupied.begin(),occupied.end());
    
    //我需要一个最短路径算法，任意两点间的，所以抄了一个floyd.

    memset(dist, 0x3f, sizeof(dist)); // 使用0x3f填充，表示无穷大
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0; // 自己到自己的距离为0
    }

    // 填充dist数组
    for (int i = 0; i < n; i++) {
        for (auto &p : graph[i]) {
            dist[p.from][p.to] = min(dist[p.from][p.to], p.d);
            dist[p.to][p.from] = min(dist[p.to][p.from], p.d); // 无向图
        }
    }

    // Floyd-Warshall算法
    for (int k = 0; k < n; k++) { // 中间顶点
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) { // 防止溢出
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    dfs(s,0);


    cout<<maxd;
}