#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 10010;
struct Node {
    string data;
    vector<int> child;
} node[MAXN];
int n, m;
int father[MAXN]; // 存放父亲结点
bool isRoot[MAXN]; // 记录每个结点是否作为某个集合的根结点
int findFather(int x) { // 查找x所在集合的根结点
    int a = x;
    while(x != father[x]) {
       x = father[x];
    }
    // 路径压缩
    while(a != father[a]) {
       int z = a;
       a = father[a];
       father[z] = x;
    }
    return x;
}
void Union(int a, int b) { // 合并a和b所在的集合
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB) {
        if(faA < faB) {     // 以较小编号的作为fater
            father[faB] = faA;
        } else {
            father[faA] = faB;
        }
    }
}
void init(int n) { // 初始化father[i]为i，且flag[i]为false
    for(int i = 0; i < n; i++) {
        father[i] = i;
        isRoot[i] = false;
    }
}
string removeLeadingZero(string str) {      // 去掉前导0
    while(str.length() > 1 && str.back() == '0') {
        str.pop_back();
    }
    return str;
}
string sum = "0", tempSum = "";     // 和，临时和
string getSum(string a, string b) {     // 求大整数的和
    string result = "";
    int carry = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for(int i = 0; i < a.length() || i < b.length() || carry; i++) {
        int numA = i < a.length() ? (a[i] - '0') : 0;
        int numB = i < b.length() ? (b[i] - '0') : 0;
        result += (numA + numB + carry) % 10 + '0';
        carry = (numA + numB + carry) / 10;
    }
    result = removeLeadingZero(result);
    reverse(result.begin(), result.end());
    return result;
}
void DFS(int u) {   // 先序，求整棵树的所有从根到叶子所代表的数的和
    if(!node[u].child.size()) {     // 递归边界，叶子结点
        sum = getSum(sum, tempSum);     // sum = sum + tempSum
        return;
    }
    for(int i = 0; i < node[u].child.size(); i++) {     // 遍历所有子结点
        int v = node[u].child[i];   // v为子结点编号
        tempSum += node[v].data;    // 临时和拼接上这个数位
        DFS(v);     // 递归遍历以子结点v为根节点的树
        tempSum.pop_back();     // 把刚才拼接上的数位去掉
    }
}
int main() {
    scanf("%d%d", &n, &m);
    init(n);        // 初始化
    for(int i = 0; i < n; i++) {
        char str[2];
        scanf("%s", str);
        node[i].data = string(str);     // 结点数据域
    }
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        Union(u, v);    // 合并u和v所在的两棵树
        node[u].child.push_back(v);     // 建边u->v
    }
    for(int i = 0; i < n; i++) {
        isRoot[findFather(i)] = true; // i的根结点是findFather(i)
    }
    int num = n - m;
    printf("%d\n", num);    // 树的个数等于点数减去边数
    for(int i = 0; i < n; i++) {    // 遍历所有结点
        if(isRoot[i]) { // 如果是一棵树的根
            sum = "0";  // 初始化sum为0
            tempSum = node[i].data;     // 初始化临时和为根节点的数
            DFS(i);     // 递归求解整棵树的和
            printf("%s", sum.c_str());  // 输出结果
            if(--num) {
                printf(" ");    // 格式控制
            }
        }
    }
    printf("\n");
    return 0;
}