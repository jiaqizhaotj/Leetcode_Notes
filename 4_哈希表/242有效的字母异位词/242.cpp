#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


// LC： https://leetcode.cn/problems/valid-anagram/description/

// 哈希表 使用数组 2023.12.19

// 字符串只有小写字符.那么就可以定义一个数组.来记录字符串s里字符出现的次数.
// 因为字符a到字符z的ASCII是26个连续的数值,所以字符a映射为下标0, 相应的字符z映射为下标25.
// 再遍历 字符串s的时候.只需要将 s[i] - 'a' 所在的元素做+1 操作即可.并不需要记住字符a的ASCII.只要求出一个相对数值就可以了。这样就将字符串s中字符出现的次数.统计出来了。
// 同样在遍历字符串t的时候,对t中出现的字符映射哈希表索引上的数值再做-1的操作.
// 那么最后检查一下,record数组如果有的元素不为零0,说明字符串s和t一定是谁多了字符或者谁少了字符, return false.
// 最后如果record数组所有元素都为零0,说明字符串s和t是字母异位词, return true.

// 时间复杂度: O(n)
// 空间复杂度: O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        int hash[26] = {0}; // 并不需要记住字符a的ASCII，只要求出一个相对数值就可以了
        // vector<int> table(26, 0); 也可以用vector构建数组
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            hash[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (hash[i] != 0) {
                return false; // record数组如果有的元素不为零0，说明字符串s和t 一定是谁多了字符或者谁少了字符。
            }
        }
        return true; // record数组所有元素都为零0，说明字符串s和t是字母异位词
    }
};

// 进阶问题
// Unicode 一个字符可能对应多个字节的问题
// 时间复杂度：O(n),其中 n 为 s 的长度。
// 空间复杂度：O(S),S 为字符集大小,此处 S=26



// 排序(官方解答)
// t 是 s 的异位词等价于「两个字符串排序后相等」。因此我们可以对字符串 s 和 t 分别排序，看排序后的字符串是否相等即可判断。此外，如果 s 和 t 的长度不同，t 必然不是 s 的异位词。
// 时间复杂度：O(nlog⁡n) 
// 空间复杂度：O(log⁡n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
