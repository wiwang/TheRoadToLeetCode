/*
 * @lc app=leetcode id=139 lang=java
 *
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (36.94%)
 * Likes:    3165
 * Dislikes: 170
 * Total Accepted:    436.4K
 * Total Submissions: 1.2M
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
 * 
 * Note:
 * 
 * 
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
 * 
 * 
 */

/**
dp[i] = Or(dp[j] and str[j--i] in dict) for j is from 0 to i-1
*/

// @lc code=start
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        int len = s.length();

        boolean[] result = new boolean[len+1];
        for (boolean b : result) {
            b = false;
        }

        result[0] = true;
        for (int i = 1; i <= len; i++) {
            if (!result[i] && isWord(wordDict, s.substring(0, i))) {
                result[i] = true;
            }

            if (result[i]) {
                for (int j = i+1; j <= len; j++) {
                    if (isWord(wordDict, s.substring(i, j))) {
                        result[j] = true;
                    }
                }
            }
        }

        return result[len];
    }

    private boolean isWord(List<String> wordDict, String s) {
        for (String  word: wordDict) {
            if (word.equals(s)) {
                return true;
            }
        }

        return false;
    }
}
// @lc code=end

