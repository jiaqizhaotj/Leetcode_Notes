#include <iostream>
#include <vector>
using namespace std;

// LC: https://leetcode.cn/problems/search-insert-position/


// 二分法 2023.12.14 
// 左闭右闭
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] > target) {
                right = mid - 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                return mid;
            }
        }
        // left 或者 right+1
        return left; //返回插入的位置，注意每次while循环后如果没有找到target, left和right会各自变动
    }
};

// 左闭右开




// 左开右开



// LC官方解答 （可以省略ans）
// 不断用二分法逼近查找第一个大于等于 target 的下标 
// 时间复杂度：O(log⁡n)，其中 n 为数组的长度。二分查找所需的时间复杂度为 O(log⁡n)O。
// 空间复杂度：O(1)。我们只需要常数空间存放若干变量。





// 测试用例 nums = [1, 3, 5, 6]; target = 2; target = 7;