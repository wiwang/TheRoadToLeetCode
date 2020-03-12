/*
 * @lc app=leetcode id=67 lang=java
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (40.94%)
 * Likes:    1223
 * Dislikes: 228
 * Total Accepted:    355K
 * Total Submissions: 862.9K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 */

// @lc code=start
class Solution {
    public String addBinary(String a, String b) {
        int i = a.length()-1;
        int j = b.length()-1;
        int carry = 0;
        StringBuilder result = new StringBuilder();

        while (i>=0 || j>=0) {
            int sum = carry;
            if (i >= 0) {
                sum += a.charAt(i--)-'0';
            }

            if (j >= 0) {
                sum += b.charAt(j--)-'0';
            }

            result.append(sum%2);
            carry = sum/2;
        }

        if (carry == 1) {
            result.append('1');
        }

        return result.reverse().toString();
    }
}
// @lc code=end

