

/*
 * @lc app=leetcode id=9 lang=java
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (45.25%)
 * Likes:    1667
 * Dislikes: 1397
 * Total Accepted:    701.4K
 * Total Submissions: 1.6M
 * Testcase Example:  '121'
 *
 * Determine whether an integer is a palindrome. An integer is a palindrome
 * when it reads the same backward as forward.
 * 
 * Example 1:
 * 
 * 
 * Input: 121
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * Follow up:
 * 
 * Coud you solve it without converting the integer to a string?
 * 
 */

// @lc code=start
class Solution {
    public boolean isPalindrome(int x) {
        int left = x;
        int right = 0;
        
        if (x < 0 || (x%10==0&&x!=0)) {
            return false;
        }

        while (left > right) {     
            right=right*10+left%10;
            left = left/10;
        }

        return (left==right) || (left==right/10);
    }
}
// @lc code=end

