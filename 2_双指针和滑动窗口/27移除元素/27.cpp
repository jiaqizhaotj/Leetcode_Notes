#include <iostream>
#include <vector>
using namespace std;


// 快慢指针 2023.12.13
// 时间复杂度：O(n)
// 空间复杂度：O(1)

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (val != nums[fastIndex]) {
                nums[slowIndex] = nums[fastIndex];
                slowIndex += 1;
            }
        }
        return slowIndex;
    }
};

// int main() {
//     int a[] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
//     vector<int> cost(a, a + sizeof(a) / sizeof(int));
//     Solution solution;
//     cout << solution.minCostClimbingStairs(cost) << endl;
// }