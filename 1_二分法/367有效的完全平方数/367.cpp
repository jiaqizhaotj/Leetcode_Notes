#include <iostream>
#include <vector>
using namespace std;

// LC: https://leetcode.cn/problems/valid-perfect-square/

// 二分搜索 2023.12.14
// 左闭右闭
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0;
        int right = num;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if ((long long)mid * mid < num) {
                left = mid + 1;
            }
            else if ((long long)mid * mid > num) {
                right = mid - 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};