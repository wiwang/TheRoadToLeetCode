import java.util.HashSet;

/*
 * @lc app=leetcode id=3 lang=java
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.99%)
 * Likes:    6860
 * Dislikes: 409
 * Total Accepted:    1.2M
 * Total Submissions: 4.1M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int max = 0;
        int begin = 0;
        int end = 0;
        HashSet<Character> window = new HashSet<>();

        while (end < s.length()) {
            char c = s.charAt(end);
            if (!window.contains(c)) {
                window.add(c);
                end++;
                max = Math.max(max, end-begin);
            } else {
                window.remove(s.charAt(begin));
                begin++;
            }
        }
        
        return max;
    }
}
// @lc code=end

