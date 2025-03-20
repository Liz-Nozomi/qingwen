#include <iostream>
#include <string>
using namespace std;

const int MAXN = 100000 + 10; // 定义数组最大长度

char minChar[MAXN]; // 存储每个位置之后的最小字符
int minPos[MAXN];   // 存储最小字符的最右边位置

int main() {
    string s;
    cin >> s;
    int n = s.size();

    if (n == 0) {
        cout << s << endl;
        return 0;
    }

    // 预处理minChar和minPos数组
    minChar[n - 1] = s[n - 1];
    minPos[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        if (s[i] < minChar[i + 1]) {
            // 当前字符比后面的最小字符还小，更新为当前字符
            minChar[i] = s[i];
            minPos[i] = i;
        } else if (s[i] == minChar[i + 1]) {
            // 当前字符等于后面的最小字符，保持字符，取后面的最右位置
            minChar[i] = s[i];
            minPos[i] = minPos[i + 1];
        } else {
            // 当前字符大于后面的最小字符，继承后面的信息
            minChar[i] = minChar[i + 1];
            minPos[i] = minPos[i + 1];
        }
    }

    // 寻找第一个可以交换的位置
    for (int i = 0; i < n; ++i) {
        if (s[i] > minChar[i]) {
            // 交换当前字符和之后最小的最右字符
            swap(s[i], s[minPos[i]]);
            break;
        }
    }

    cout << s << endl;
    return 0;
}