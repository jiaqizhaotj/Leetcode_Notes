#include <iostream>
#include <vector>
using namespace std;

// LC： https://leetcode.cn/problems/binary-search/
// 位运算 https://www.zhihu.com/question/38206659
// 视频讲解
// 文字讲解

// 二分法
// 左闭右闭 2023.12.14
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;  // 定义target在左闭右闭的区间里，[left, right]
        while (left <= right) { // 当left==right，区间[left, right]依然有效，所以用 <=
            int mid = left + ((right - left) >> 1); // 防止溢出 等同于(left + right)/2 位运算更快
            if (nums[mid] > target) {
                right = mid - 1; // target 在左区间，所以[left, middle - 1]
            }
            else if (nums[mid] < target) {
                left = mid + 1; // target 在右区间，所以[middle + 1, right]
            }
            else { // nums[middle] == target
                return mid; // 数组中找到目标值，直接返回下标
            }
        }
        return -1; // 未找到目标值
    }
};

// 左闭右开 2023.12.14

