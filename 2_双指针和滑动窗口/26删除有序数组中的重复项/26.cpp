#include <iostream>
#include <vector>
using namespace std;

// LC: https://leetcode.cn/problems/remove-duplicates-from-sorted-array/

// 双指针 2023.12.13
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1) {
            return 1;
        }

        int slowIndex = 0;
        for (int fastIndex = 1; fastIndex < nums.size(); fastIndex++) {
            if (nums[slowIndex] != nums[fastIndex] ) {
                slowIndex += 1;
                nums[slowIndex] = nums[fastIndex];
            }
        }
        return slowIndex+1;
    }
};