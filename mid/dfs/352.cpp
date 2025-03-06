#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 50;

struct Node {
    int data;
    int l, r;
} nodes[MAXN];

int nodeCount = 0;

int newNode(int data) {
    nodes[nodeCount].data = data;
    nodes[nodeCount].l = nodes[nodeCount].r = -1;
    return nodeCount++;
}

int insert(int root, int data) {
    if (root == -1) {
        return newNode(data);
    }
    if (data < nodes[root].data) {
        nodes[root].l = insert(nodes[root].l, data);
    } else {
        nodes[root].r = insert(nodes[root].r, data);
    }
    return root;
}

vector<int> pre;

void preOrder(int root) {
    if (root == -1) {
        return;
    }
    pre.push_back(nodes[root].data);
    preOrder(nodes[root].l);
    preOrder(nodes[root].r);
}

int main() {
    int n, data, root = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }
    preOrder(root);
    for (int i = 0; i < (int)pre.size(); i++) {
        printf("%d", pre[i]);
        if (i < (int)pre.size() - 1) {
            printf(" ");
        }
    }
    return 0;
}