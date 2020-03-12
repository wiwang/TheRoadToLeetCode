/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (32.20%)
 * Likes:    3031
 * Dislikes: 219
 * Total Accepted:    296K
 * Total Submissions: 912.5K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * 
 * Example:
 * 
 * 
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * 
 * 
 * Note:
 * 
 * 
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 * 
 * 
 */

// @lc code=start
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> table;
        
        // initialize frequency table for t
        for(char c : t){
            table[c]++;
        }
        
        // initialize sliding window
        int begin = 0, end = 0;
        int counter = table.size();
        int len = INT_MAX;
        
        string ans = "";
        
        // start sliding window
        while(end < s.length()){
            char endchar = s[end];
            
            // if current char found in table, decrement count
            if(table.find(endchar) != table.end()){
                table[endchar]--;
                if(table[endchar] == 0) counter--;
            }
            
            end++;
            
            // if counter == 0, means we found an answer, now try to trim that window by sliding begin to right.
            while(counter == 0){
                // store new answer if smaller than previously best
                if(end-begin < len){
                    len = end - begin;
                    ans = s.substr(begin, end - begin); 
                }
                
                // begin char could be in table or not, 
                // if not then good for us, it was a wasteful char and we shortened the previously found substring.
                
                // if found in table increment count in table, as we are leaving it out of window and moving ahead, 
                // so it would no longer be a part of the substring marked by begin-end window
                // table only has count of chars required to make the present substring a valid candidate
                // if the count goes above zero means that the current window is missing one char to be an answer candidate
                int startchar = s[begin];
                
                if(table.find(startchar) != table.end()){
                   table[startchar]++;
                   if(table[startchar] == 1) counter++; 
                }
                
                begin++;
            }
        }
        
        return ans;
    }
};
// @lc code=end

