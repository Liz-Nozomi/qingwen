#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// 递归函数，用于计算插入加号后的结果之和
// num_str表示数字的字符串形式，index表示当前处理到的字符位置，current_sum表示当前的和，result_sum表示所有方案的结果之和
void calculateSums(const string& num_str, int index, int current_sum, int& result_sum) {
    // 如果已经处理到字符串的末尾，将当前和加到结果和中
    if (index == num_str.size()) {
        result_sum += current_sum;
        return;
    }

    // 不插入加号，将当前字符表示的数字加到当前和中，继续递归处理下一个字符
    int num = current_sum * 10 + (num_str[index] - '0');
    calculateSums(num_str, index + 1, num, result_sum);

    // 插入加号，将当前字符表示的数字作为新的加数，继续递归处理下一个字符
    if (index > 0) { // 不能在第一个字符前插入加号
        calculateSums(num_str, index + 1, num_str[index] - '0', result_sum);
    }
}

int main() {
    string num_str;
    cin >> num_str;

    int result_sum = 0;
    calculateSums(num_str, 0, 0, result_sum);

    cout << result_sum << endl;

    return 0;
}