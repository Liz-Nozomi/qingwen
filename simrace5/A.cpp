#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int K;
    string T;
    cin >> K >> T;
    
    int n = T.length();
    int maxLength = 0;
    int bestStart = 0;
    
    // 滑动窗口的两个指针
    for (int start = 0; start < n; start++) {
        // 从start开始，尝试扩展end
        int maxDiff = 0;
        for (int end = start; end < n; end++) {
            // 计算当前start到end的字母差距
            for (int i = start; i < end; i++) {
                maxDiff = max(maxDiff, abs(T[i] - T[end]));
            }
            if (maxDiff > K) {
                break;
            }
            // 如果合法，更新最长子串
            if (end - start + 1 > maxLength) {
                maxLength = end - start + 1;
                bestStart = start;
            }
        }
    }
    
    cout << T.substr(bestStart, maxLength) << endl;
    
    return 0;
}