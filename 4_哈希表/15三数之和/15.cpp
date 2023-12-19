#include <iostream>
#include <vector>
#include <algorithm> // 使用sort函数的头文件 sort函数用法：https://xulinjie.blog.csdn.net/article/details/76222112?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-1-76222112-blog-102548598.235%5Ev39%5Epc_relevant_3m_sort_dl_base3&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-1-76222112-blog-102548598.235%5Ev39%5Epc_relevant_3m_sort_dl_base3&utm_relevant_index=1
using namespace std;

// LC：https://leetcode.cn/problems/3sum/description/

// 标签 双指针+排序 2023.12.15
// 本题的难点在于如何去除重复解!!!
// 时间复杂度：O(n2)，数组排序 O(Nlog⁡N)，遍历数组 O(n)，双指针遍历 O(n)，总体 O(Nlog⁡N)+O(n)∗O(n)，O(n^2)
// 空间复杂度: O(1)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 对数组中的元素排序(从小到大)
        sort(nums.begin(), nums.end());
        // 输出答案的数组(其中元素也为数组)
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size() - 2; i++) { 
            // 优化：如果 nums[i] > 0, 则直接退出循环
            if (nums[i] > 0) break;
            // 二分搜索
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) { // 此处使用 left < right, 因为需要找到两个对应的数
                int sum = nums[i] + nums[left] + nums[right];
                // 第一个指针指向nums[i], 之后只要寻找 nums[left] + nums[right] + nums[i] == 0
                if (sum > 0) {
                    right--;
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    // 继续搜索其他符合条件的组合，但要去除重复数字!!! left++; right--; !!!
                    // 如果left右移，nums[left + 1] == nums[left], 跳过, 直到找到left右侧下一个不同的数字
                    // 如果right左移，nums[right - 1] == nums[right], 跳过, 直到找到right左侧下一个不同的数字
                    left++; 
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    right--;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
            }
            // 判断完当前nums[i]对应的所有组合以后，准备i + 1的组合，但如果nums[i] == nums[i + 1], 则需要跳过， 避免重复结果
            // 判断重复条件，跳过重复数字!!!
            if (nums[i] == nums[i + 1]) i++;
        }
        return ans;
    }
};
