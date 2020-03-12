import java.util.Stack;

/*
 * @lc app=leetcode id=32 lang=java
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (26.54%)
 * Likes:    2574
 * Dislikes: 112
 * Total Accepted:    235.9K
 * Total Submissions: 876.1K
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * Example 1:
 * 
 * 
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 * 
 * 
 */

/**
 * one method is to use stack
 */


// @lc code=start
class Solution {
    public int longestValidParentheses(String s) {
        if (s == null) {
            return 0;
        }

        Stack<Integer> tmp = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (!tmp.isEmpty() && (c==')'&& s.charAt(tmp.peek())=='(')) {
                tmp.pop();
            } else {
                tmp.push(i);
            }
        }

        //go through the index in stack to find the longest valid parentheses
        int max = 0;
        int current = s.length();

        while (!tmp.isEmpty()) {
            int index = tmp.pop();
            max = Math.max(max, current-index-1);
            current = index;
        }
        max = Math.max(max, current);

        return max;
    }
}
// @lc code=end

