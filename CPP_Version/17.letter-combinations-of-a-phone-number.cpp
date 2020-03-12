/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (43.38%)
 * Likes:    2715
 * Dislikes: 343
 * Total Accepted:    466.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> result;
    string tmp;
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0)
        {
            return result;
        }

        exploreCombinations(digits, 0);
        return result;
    }

    void exploreCombinations(string digits, int start) {
        if (start == digits.length())
        {
            result.push_back(tmp);
        }
        else
        {
            for (char c : getMappedString(digits[start]))
            {
                tmp.push_back(c);
                exploreCombinations(digits, start+1);
                tmp.pop_back();
            }
        }
    }

    string getMappedString(char digit) {
        string result;
        switch (digit)
        {
        case '2':
            result = "abc";
            break;
        case '3':
            result = "def";
            break;
        case '4':
            result = "ghi";
            break;
        case '5':
            result = "jkl";
            break;
        case '6':
            result = "mno";
            break;
        case '7':
            result = "pqrs";
            break;
        case '8':
            result = "tuv";
            break;
        case '9':
            result = "wxyz";
            break;            
        
        default:
            break;
        }

        return result;
    }
};
// @lc code=end

