#include <iostream>
#include <vector>
#include <math.h> // sqrt头文件
using namespace std;

// LC: https://leetcode.cn/problems/sum-of-square-numbers/description/

// 二分搜索 2023.12.14 
class Solution {
public:
    bool judgeSquareSum(int c) {
        // 可能的组合出现在 a = 0 和 b = sqrt（c）之间
        long a = 0;
        long b = (int) sqrt(c);
        while (a <= b) {
            long sum = a * a + b * b;
            if (sum > c) {
                b--; // 如果 sum > c, 则 b--
            }
            else if (sum < c) {
                a++; // 如果 sum < c, 则 a++
            }
            else {
                return true; //找到对应的a和b
            }
        }
        return false; 
    }
};