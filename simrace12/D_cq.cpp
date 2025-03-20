#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef pair<int, int> pii;
vector<vector<int> > result; // 存储路径（节点序列）

void dfs(int pos, int end, vector<vector<pii>>& adj, vector<int>& path, vector<bool>& visit) {
    if (pos == end) {
        result.push_back(path);
        return;
    }
    for (auto t : adj[pos]) {
        int u = t.first;
        if (!visit[u]) {
            visit[u] = true;
            path.push_back(u);
            dfs(u, end, adj, path, visit);
            path.pop_back();
            visit[u] = false;
        }
    }
}

bool qualified(vector<int>& path, vector<vector<pii>>& adj, int threshold) {
    int total = 0;
    for (int i = 0; i < path.size() - 1; i++) {
        int u = path[i], v = path[i + 1];
        for (auto edge : adj[u]) {
            if (edge.first == v) {
                total += edge.second;
                break;
            }
        }
    }
    return total <= threshold;
}

int findD(vector<int>& lang, int target) {
    auto it = lower_bound(lang.begin(), lang.end(), target);
    int dist = INT_MAX;
    if (it != lang.end()) {
        dist = min(dist, abs(*it - target));
    }
    if (it != lang.begin()) {
        dist = min(dist, abs(*(it - 1) - target));
    }
    return dist;
}

int main() {
    int n, m, t, k;
    cin >> n >> m >> t;
    vector<vector<pii>> adj(n);
    vector<int> l(n);
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }
    int s, target;
    cin >> s >> target;
    vector<int> path;
    vector<bool> visit(n, false);
    path.push_back(s);
    visit[s] = true;
    dfs(s, target, adj, path, visit);

    cin >> k;
    vector<int> lang(k);
    for (int i = 0; i < k; i++) {
        cin >> lang[i];
    }
    sort(lang.begin(), lang.end());
    for(int i=0;i<n;i++){
        l[i] = findD(lang, i);
    }
    int max_result = 0;
    for (auto& temp : result) {
        if (qualified(temp, adj, t)) {
            int min_d = INT_MAX;
            for (int node_value : temp) {
                min_d = min(min_d, l[node_value]);
            }
            max_result = max(max_result, min_d);
        }
    }
    cout << max_result;
    return 0;
}