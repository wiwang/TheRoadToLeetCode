/*
 * @lc app=leetcode id=140 lang=java
 *
 * [140] Word Break II
 *
 * https://leetcode.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (28.51%)
 * Likes:    1367
 * Dislikes: 302
 * Total Accepted:    191.1K
 * Total Submissions: 655.4K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, add spaces in s to construct a sentence where each word is
 * a valid dictionary word. Return all such possible sentences.
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
 * Input:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * Output:
 * [
 * "cats and dog",
 * "cat sand dog"
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * Output:
 * [
 * "pine apple pen apple",
 * "pineapple pen apple",
 * "pine applepen apple"
 * ]
 * Explanation: Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output:
 * []
 * 
 */

// @lc code=start
class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        ArrayList<String> result = new ArrayList<>();

        String tmp = new 
        
    }

    private boolean findWordBreak(String s, List<String> wordDict, String tmp) {

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

