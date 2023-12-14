#include <iostream>
#include <vector>
using namespace std;

// LC: https://leetcode.cn/problems/squares-of-a-sorted-array/

// 双指针 从两侧往里逼近 2023.12.14
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // 创建结果数组(重要！构建数组大小和初始化)！！！
        vector<int> ans(nums.size(), 0);
        // 定义原nums数组的左右指针
        int leftIndex = 0;
        int rightIndex = nums.size() - 1;
        // 定义结果数组ans中的指针，将结果由大到小排列
        int k = nums.size() - 1;

        while (leftIndex <= rightIndex) {
            int square1 = nums[leftIndex] * nums[leftIndex];
            int square2 = nums[rightIndex] * nums[rightIndex];
            if (square1 <= square2) {
                ans[k--] = square2;
                rightIndex--;
            }
            else if (square1 > square2) {
                ans[k--] = square1;
                leftIndex++;
            }
        }
        return ans;
    }
};

// 双指针 


// 暴力解法，排序！