#include <bits/stdc++.h>
using namespace std;



int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // 使用固定种子初始化 Mersenne Twister 随机数生成器
    std::mt19937 rng(time(0)); // 种子为当前时间

    // 使用 std::shuffle 打乱 vector 中的元素
    std::shuffle(vec.begin(), vec.end(), rng);

    // 输出打乱后的 vector
    for (int i : vec) {
        std::cout << i << " ";
    }

    return 0;
}