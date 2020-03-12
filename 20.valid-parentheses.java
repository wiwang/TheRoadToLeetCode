import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

/*
 * @lc app=leetcode id=20 lang=java
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (37.40%)
 * Likes:    3647
 * Dislikes: 176
 * Total Accepted:    762.5K
 * Total Submissions: 2M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */

// @lc code=start
class Solution {
    public boolean isValid(String s) {
        Map<Character,Character> m = new HashMap<>();
        m.put(')', '(');
        m.put(']', '[');
        m.put('}', '{');

        Stack<Character> tmp = new Stack<>();

        if (s=="") {
            return true;
        }
        
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c=='{' || c=='[' || c=='(') {
                tmp.push(c);
            } else {
                if (tmp.isEmpty()) {
                    return false;
                }
                if (m.get(c) != tmp.peek()) {
                    return false;
                }
                tmp.pop();
            }
        }

        return tmp.isEmpty()?true:false;
    }
}
// @lc code=end

