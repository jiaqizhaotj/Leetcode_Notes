#include <iostream>
#include <vector>
using namespace std;

// LC: https://leetcode.cn/problems/spiral-matrix-ii/
// 视频讲解 https://www.bilibili.com/video/BV1SL4y1N7mV/?spm_id_from=333.788&vd_source=fa7e32efa9ced83b340587ae50ea0b67
// 文字讲解 https://www.programmercarl.com/0059.%E8%9E%BA%E6%97%8B%E7%9F%A9%E9%98%B5II.html


// 使用vector一次性完成二维数组的定义（注意：此种方法适用于每一行的列数相等的二维数组）
// vector<vector<int>> matrix(m, vector<int>(n, -1));
// 以下是拆分理解
// 创建一维数组matirx，这个数组里有m个元素，元素是int型vector。
// vector<vector<int>> matrix(m);
// 除了定义数组类型及数组大小外，同时给数组中的元素赋值：将元素赋值为大小为n的int型vector。
// vector<vector<int>> matrix(m, vector<int>(n));
// 除了定义数组类型、数组大小、列的大小，同时给数组列中的元素（或者说，数组中的所有元素）赋值为-1。
// vector<vector<int>> matrix(m, vector<int>(n, -1));

// 标签：模拟
// 时间复杂度 O(n^2): 模拟遍历二维矩阵的时间
// 空间复杂度 O(1)

// ！！！循环不变量：每次都是左闭右开。

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n,0)); //使用vector定义一个 n * n 二维数组
        int startx, starty = 0; // 定义每循环一个圈的起始位置
        int loop = n >> 1; // 每个圈循环几次，例如n为奇数3，那么loop = 1 只是循环一圈，矩阵中间的值需要单独处理
        int mid = n >> 1; // 矩阵中间的位置，例如：n为3， 中间的位置就是(1，1)，n为5，中间位置为(2, 2)
        int offset = 1; // 需要控制每一条边遍历的长度，每次循环右边界收缩一位。
        int count = 1;
        int i, j;
        while (loop--) {
            // 下面开始的四个for就是模拟转了一圈
            // 以n = 5为例，第一圈应该是[0][0]到[0][3],然后是[0][4]到[3][3],然后是[3][4]到[3][1],最后是[3][0]到[1][0]。
            // 第二圈为[1][1]到[1][2],[1][3]到[2][3],[3][3]到[3][2],[3][1]到[2][1]。
            // 由于n为奇数，中心点需要额外处理。所以[2][2] = [mid][mid]。

            // 模拟填充上行从左到右(左闭右开)
            for (j = starty; j < n - offset; j++) {
                matrix[startx][j] = count++;
            }
            // 模拟填充右列从上到下(左闭右开)
            for (i = startx; i < n - offset; i++) {
                matrix[i][j] = count++;
            }
            // 模拟填充下行从右到左(左闭右开)
            // i初始值保持不变，所以不做额外初始化
            for ( ; j > starty; j--) {
                matrix[i][j] = count++;
            }
            // 模拟填充左列从下到上(左闭右开)
            // j初始值保持不变，所以不做额外初始化
            for ( ; i > startx; i--) {
                matrix[i][j] = count++;
            }
            // 第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
            startx++; starty++;
            // offset 控制每一圈里每一条边遍历的长度
            offset++;
        }
        // 如果n为奇数的话，需要单独给矩阵最中间的位置赋值
        if (n % 2 == 1) {
                matrix[mid][mid] = count;
        }
        return matrix;
    }
};