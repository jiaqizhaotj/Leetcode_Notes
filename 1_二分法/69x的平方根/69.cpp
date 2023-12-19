#include <iostream>
#include <vector>
using namespace std;

// LC: https://leetcode.cn/problems/sqrtx/
// 标签：二分查找


// 可以看一下这个解析 https://leetcode.cn/problems/sqrtx/solutions/7866/er-fen-cha-zhao-niu-dun-fa-python-dai-ma-by-liweiw/

// 如果这个整数的平方 恰好等于 输入整数，那么我们就找到了这个整数； (long long)mid * mid == x
// 猜的数平方以后大了就往小了猜； right = mid - 1;

// 如果这个整数的平方 严格大于 输入整数，那么这个整数肯定不是我们要找的那个数；(long long)mid * mid > x
// 猜的数平方以后恰恰好等于输入的数就找到了； return mid;

// ！！！如果这个整数的平方 严格小于 输入整数，那么这个整数 可能 是我们要找的那个数（重点理解这句话）。 (long long)mid * mid < x  !!!
// 猜的数平方以后小了，可能猜的数就是，也可能不是。


// 二分搜索 2023.12.14
// 左闭右闭
class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if ((long long)mid * mid < x) {
                left = mid + 1;
            }
            else if ((long long)mid * mid > x) {
                right = mid - 1;
            }
            else {
                return mid;
            }
        }
        // 
        return left - 1;
    }
};