/*
 * @lc app=leetcode id=3 lang=cpp
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
 *     int lengthOfLongestSubstring(string s) {
        unordered_set<char> sub;

        int begin = 0;
        int end = 0;
        int maxLength = 0;

        while (end < s.length())
        {
            char e = s[end];
            if (sub.find(e) == sub.end())
            {
                sub.insert(e);
                end++;

                maxLength = max(maxLength, end-begin);
            }
            else
            {
                sub.erase(s[begin]);
                begin++;
            }
        }
        
        return maxLength;
    }
 * 
 * 
 * 
 */

// @lc code=start
#include <unordered_map>

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int begin = 0;
        int end = 0;
        int maxLength = 0;

        while (end < s.length())
        {
            char e = s[end];
            if (map.find(e) != map.end())
            {
                begin = max(begin, map[e]+1);
            }

            maxLength = max(maxLength, end-begin+1);

            map[e] = end;
            end++;
        }
        
        return maxLength;
    }
};
// @lc code=end

