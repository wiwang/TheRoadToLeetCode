/*
 * @lc app=leetcode id=28 lang=java
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (33.09%)
 * Likes:    1173
 * Dislikes: 1598
 * Total Accepted:    541.6K
 * Total Submissions: 1.6M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */

// @lc code=start
class Solution {
    public int strStr(String haystack, String needle) {
        int m = haystack.length();
        int n = needle.length();

        if (n==0) {
            return 0;
        }

        for (int i = 0; i < m-n+1; i++) {
            if (isMatch(haystack, needle, i)) {
                return i;
            }
        }

        return -1;
    }

    private boolean isMatch(String haystack, String needle, int pos) {
        for (int i = 0; i < needle.length(); i++) {
            if (haystack.charAt(pos+i) != needle.charAt(i)) {
                return false;
            }
        }

        return true;
    }
}
// @lc code=end

