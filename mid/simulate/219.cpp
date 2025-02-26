#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef vector<int> BigInt;

BigInt toBigInt(string nums) {
    BigInt result;
    for (int i = (int)nums.length() - 1; i >= 0; i--) {
        result.push_back(nums[i] - '0');
    }
    return result;
}

int compare(BigInt a, BigInt b) {
    if (a.size() > b.size()) {
        return 1;
    } else if (a.size() < b.size()) {
        return -1;
    } else {
        for (int i = (int)a.size() - 1; i >= 0; i--) {
            if (a[i] > b[i]) {
                return 1;
            } else if (a[i] < b[i]) {
                return -1;
            }
        }
        return 0;
    }
}

BigInt sub(BigInt a, BigInt b) {
    BigInt c;
    int carry = 0;
    for (int i = 0; i < a.size(); i++) {
        int bDigit = i < b.size() ? b[i] : 0;
        if (a[i] < bDigit) {
            a[i + 1]--;
            a[i] += 10;
        }
        c.push_back(a[i] - bDigit);
    }
    while (c.size() > 1 && c.back() == 0) {
        c.pop_back();
    }
    return c;
}

void print(BigInt a) {
    for (int i = (int)a.size() - 1; i >= 0; i--) {
        cout << a[i];
    }
}

int main() {
    string nums1, nums2;
    cin >> nums1 >> nums2;
    BigInt a = toBigInt(nums1);
    BigInt b = toBigInt(nums2);
    if (compare(a, b) >= 0) {
        print(sub(a, b));
    } else {
        cout << "-";
        print(sub(b, a));
    }
    return 0;
}