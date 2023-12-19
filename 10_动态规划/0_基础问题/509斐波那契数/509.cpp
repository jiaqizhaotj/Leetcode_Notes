#include <iostream>
#include <vector>
using namespace std;

// LC：https://leetcode.cn/problems/fibonacci-number/

// 动态规划
// 时间复杂度: O(n)
// 空间复杂度: O(n)
class Solution {
public:
    int fib(int n) {
        if (n <= 0) return n;
        vector<int> dp(n + 1);
        // dp数组初始化
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i < n + 1; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// 动态规划
// 时间复杂度: O(n)
// 空间复杂度: O(1)
class Solution {
public:
    int fib(int N) {
        if (N <= 1) return N;
        int dp[2];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= N; i++) {
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};

// 递归
// 时间复杂度: O(2^n)
// 空间复杂度: O(n)
class Solution {
public:
    int fib(int N) {
        if (N < 2) return N;
        return fib(N - 1) + fib(N - 2);
    }
}