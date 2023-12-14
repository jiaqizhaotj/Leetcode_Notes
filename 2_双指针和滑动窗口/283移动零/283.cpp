#include <iostream>
#include <vector>
using namespace std;

// LC: https://leetcode.cn/problems/move-zeroes/description/

// 双指针 2023.12.13
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (nums[fastIndex] != 0) {
                nums[slowIndex] = nums[fastIndex];
                slowIndex += 1;
            }
        }
        while (slowIndex < nums.size()) {
            nums[slowIndex] = 0;
            slowIndex += 1;
        }
    }
};